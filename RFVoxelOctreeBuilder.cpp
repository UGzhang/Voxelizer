
#include "RFVoxelOctreeBuilder.h"

#include "RFIntersectionTests.h"


using namespace std;
using namespace RFMath;
using namespace RFAxl;


// 127 --> 128
// 30 --> 32
uint32 GetNextPowerOfTwo(uint32 ui) {

  if (ui == 0) {
    return 2;
  }

  --ui;
  ui |= ui >> 16;
  ui |= ui >> 8;
  ui |= ui >> 4;
  ui |= ui >> 2;
  ui |= ui >> 1;
  ++ui;

  return ui;
}


// 32 --> 5
// 16 --> 4 
uint32 GetOrderOfTwo(uint32 ui) {
  int count = 0;
  if (ui == 1) return 0;

  while (ui > 1) {
    ui = ui >> 1;  //右移 -> 除以2的1次方
    count++;
  }
  return count;
}


const double PI = 3.14159265358979;

double RadicalInverseVdC(uint uiBits) {
  uiBits = (uiBits << 16u) | (uiBits >> 16u);
  uiBits = ((uiBits & 0x55555555u) << 1u) | ((uiBits & 0xAAAAAAAAu) >> 1u);
  uiBits = ((uiBits & 0x33333333u) << 2u) | ((uiBits & 0xCCCCCCCCu) >> 2u);
  uiBits = ((uiBits & 0x0F0F0F0Fu) << 4u) | ((uiBits & 0xF0F0F0F0u) >> 4u);
  uiBits = ((uiBits & 0x00FF00FFu) << 8u) | ((uiBits & 0xFF00FF00u) >> 8u);
  return static_cast<double>(uiBits) *
         static_cast<double>(2.3283064365386963e-10);  // / 0x100000000
}

RFMath::RFVector2f Hammersley2D(const uint i, const uint N) {
  return RFVector2f(static_cast<double>(i) / static_cast<double>(N), RadicalInverseVdC(i));
}

RFVector3d UniformSphericalSampling(double u, double v) {
  double phi = v * 2.0f * PI;
  double cosTheta = 1.0f - u;
  double sinTheta = sqrt(1.0f - cosTheta * cosTheta);
  return RFVector3d(cos(phi) * sinTheta, sin(phi) * sinTheta, cosTheta);
}

RFVoxelOctreeBuilder::RFVoxelOctreeBuilder() : m_pkVoxelOctree(nullptr) {
  for (uint i = 0; i < 200; i++) {
    RFVector2f kRand = Hammersley2D(i, 200);
    m_kSampleDirections.push_back(UniformSphericalSampling(kRand.tX, kRand.tY));
  }
}

RFVoxelOctreeBuilder::~RFVoxelOctreeBuilder() {}

RFVoxelOctree *RFVoxelOctreeBuilder::CreateOctree(
    const std::vector<RFMath::RFVector3d> &kMeshVertices, 
    const RFMath::RFAABB3d kMeshAabb,
    const double fVoxelSize, 
    const double fMinCoverage, 
    const double fBorderSize) {
  m_pkVoxelOctree = new RFVoxelOctree;
  m_pkVoxelOctree->m_fVoxelSize = fVoxelSize;
  const double fInvVoxelSize = 1.0f / fVoxelSize;

  // 1) Scale the aabb with the inv-voxelsize to find the correct octree dim in
  // voxel dimensions
  RFAABB3d kAABB = kMeshAabb;
  kAABB.kMin *= fInvVoxelSize;
  kAABB.kMax *= fInvVoxelSize;

  // 2) Find the longest axis
  RFVector3d kDim = kAABB.kMax - kAABB.kMin;
  uint uiMaxIndex = VectorIndexOfMaxAbsComponent(kDim);
  //float fMaxDim = kDim[uiMaxIndex] + fBorderSize;
  double fMaxDim = kDim[uiMaxIndex];
  m_pkVoxelOctree->m_uiOctreeDim = GetNextPowerOfTwo(static_cast<uint>(fMaxDim));

  double fOctreeWorldSize = static_cast<double>(m_pkVoxelOctree->m_uiOctreeDim) * fVoxelSize;
  m_pkVoxelOctree->m_kOctreeOrigin = kMeshAabb.GetCenter() - RFVector3d(fOctreeWorldSize / 2.0f);

  // 3) Create the initial index list, so here we assume that the vertices's are
  // ordered in triangles [v0,v1,v2] ...
  std::vector<uint> kTriangleIndexList;
  for (uint i = 0; i < kMeshVertices.size(); i += 3) {
    kTriangleIndexList.push_back(i);
  }

  // 4) Create the octree root
  RFAABB3d kRootAabb;
  kRootAabb.kMin = m_pkVoxelOctree->m_kOctreeOrigin;
  kRootAabb.kMax = m_pkVoxelOctree->m_kOctreeOrigin + RFVector3d(fOctreeWorldSize);

  m_pkVoxelOctree->m_kDataDimension = RFVector3i(static_cast<int>(m_pkVoxelOctree->m_uiOctreeDim));
  m_pkVoxelOctree->m_pkRoot = new RFVoxelOctreeNode;
  m_pkVoxelOctree->m_pkRoot->m_kWorldAabb = kRootAabb;
  m_pkVoxelOctree->m_pkRoot->m_kBuildAabb.kMin = RFVector3i(0);
  m_pkVoxelOctree->m_pkRoot->m_kBuildAabb.kMax =
      RFVector3i(static_cast<int>(m_pkVoxelOctree->m_uiOctreeDim));

  // 5) Subdivide
  Subdivide(m_pkVoxelOctree->m_pkRoot, kMeshVertices, kTriangleIndexList);
  UpdateInternalEmptyLeafsSign(m_pkVoxelOctree->m_pkRoot, m_pkVoxelOctree->m_pkRoot, fMinCoverage);
  UpdateOctreeStats(m_pkVoxelOctree);

  return m_pkVoxelOctree;
}


// add CreateOctree method in 2022.2.15 Aaron
// use Vertices, AABB box, dim
RFVoxelOctree* RFVoxelOctreeBuilder::CreateOctree(
    const std::vector<RFMath::RFVector3d>& kMeshVertices,
    const RFMath::RFAABB3d kMeshAabb,
    const uint32_t kOctreeDim, 
    const double fMinCoverage, 
    const double fBorderSize ){

  m_pkVoxelOctree = new RFVoxelOctree;
  m_pkVoxelOctree->m_uiOctreeDim = GetNextPowerOfTwo(kOctreeDim);

  RFVector3d kDim = kMeshAabb.kMax - kMeshAabb.kMin;
  uint uiMaxIndex = VectorIndexOfMaxAbsComponent(kDim);
  double fMaxDim = kDim[uiMaxIndex];
  m_pkVoxelOctree->m_fVoxelSize = fMaxDim / m_pkVoxelOctree->m_uiOctreeDim;

  double fOctreeWorldSize =
      static_cast<double>(m_pkVoxelOctree->m_uiOctreeDim) * m_pkVoxelOctree->m_fVoxelSize;

  m_pkVoxelOctree->m_kOctreeOrigin = kMeshAabb.GetCenter() - RFVector3d(fOctreeWorldSize / 2.0f);

    // 3) Create the initial index list, so here we assume that the vertices's are
  // ordered in triangles [v0,v1,v2] ...
  std::vector<uint> kTriangleIndexList;
  for (uint i = 0; i < kMeshVertices.size(); i += 3) {
    kTriangleIndexList.push_back(i);
  }

  // 4) Create the octree root
  RFAABB3d kRootAabb;
  kRootAabb.kMin = m_pkVoxelOctree->m_kOctreeOrigin;
  kRootAabb.kMax = m_pkVoxelOctree->m_kOctreeOrigin + RFVector3d(fOctreeWorldSize);

  m_pkVoxelOctree->m_kDataDimension = RFVector3i(static_cast<int>(m_pkVoxelOctree->m_uiOctreeDim));
  m_pkVoxelOctree->m_pkRoot = new RFVoxelOctreeNode;
  m_pkVoxelOctree->m_pkRoot->m_kWorldAabb = kRootAabb;
  m_pkVoxelOctree->m_pkRoot->m_kBuildAabb.kMin = RFVector3i(0);
  m_pkVoxelOctree->m_pkRoot->m_kBuildAabb.kMax =
      RFVector3i(static_cast<int>(m_pkVoxelOctree->m_uiOctreeDim));

  // 5) Subdivide
  Subdivide(m_pkVoxelOctree->m_pkRoot, kMeshVertices, kTriangleIndexList);
  UpdateInternalEmptyLeafsSign(m_pkVoxelOctree->m_pkRoot, m_pkVoxelOctree->m_pkRoot, fMinCoverage);
  UpdateOctreeStats(m_pkVoxelOctree);

  return m_pkVoxelOctree;

}



void RFVoxelOctreeBuilder::Subdivide(RFVoxelOctreeNode *pkParentNode,
                                     const std::vector<RFMath::RFVector3d> &kMeshVertices,
                                     const std::vector<uint> &kNodeTriangleIndices) {
  uint uiChildIndex = 0;
  int iAabbDim = pkParentNode->m_kBuildAabb.GetWidth() / 2;

  for (int z = 0; z < 2; z++) {
    for (int y = 0; y < 2; y++) {
      for (int x = 0; x < 2; x++) {
        RFVoxelOctreeNode *pkChildNode = new RFVoxelOctreeNode;
        pkChildNode->m_kBuildAabb.kMin =
            pkParentNode->m_kBuildAabb.kMin + RFVector3i(iAabbDim * x, iAabbDim * y, iAabbDim * z);
        pkChildNode->m_kBuildAabb.kMax = pkChildNode->m_kBuildAabb.kMin + RFVector3i(iAabbDim);
        pkParentNode->m_pkChildren[uiChildIndex] = pkChildNode;
        uiChildIndex++;
      }
    }
  }

  // Subdivide the node
  for (uint i = 0; i < 8; i++) 
  {
    RFVoxelOctreeNode *pkChildNode = pkParentNode->m_pkChildren[i];
    vector<uint> kChildTriangleIndices;
    RFAABB3d kWorldAabb;

    kWorldAabb.kMin = m_pkVoxelOctree->m_kOctreeOrigin +
                      RFVector3d(static_cast<double>(pkChildNode->m_kBuildAabb.kMin.tX),
                                 static_cast<double>(pkChildNode->m_kBuildAabb.kMin.tY),
                                 static_cast<double>(pkChildNode->m_kBuildAabb.kMin.tZ)) *
                          m_pkVoxelOctree->m_fVoxelSize;

    kWorldAabb.kMax = m_pkVoxelOctree->m_kOctreeOrigin +
                      RFVector3d(static_cast<double>(pkChildNode->m_kBuildAabb.kMax.tX),
                                 static_cast<double>(pkChildNode->m_kBuildAabb.kMax.tY),
                                 static_cast<double>(pkChildNode->m_kBuildAabb.kMax.tZ)) *
                          m_pkVoxelOctree->m_fVoxelSize;

    pkChildNode->m_kWorldAabb = kWorldAabb;

    for (uint v = 0; v < kNodeTriangleIndices.size(); v++) {
      RFVector3d kTriangleVerts[3];
      uint uiTriIndex = kNodeTriangleIndices[v];
      kTriangleVerts[0] = kMeshVertices[uiTriIndex];
      kTriangleVerts[1] = kMeshVertices[uiTriIndex + 1];
      kTriangleVerts[2] = kMeshVertices[uiTriIndex + 2];

      if (TriangleAabbIntersects(kTriangleVerts, kWorldAabb)) {
        kChildTriangleIndices.push_back(uiTriIndex);
      }
    }

    // no intersections so this child is empty
    if (kChildTriangleIndices.empty()) {
      pkChildNode->m_eNodeType = NT_EMPTY_LEAF;
    } 
    else {
      if (iAabbDim == 1)  // Got a leaf node
      {
        pkChildNode->m_eNodeType = NT_LEAF;
        UpdateLeafNodeDistanceValue(pkChildNode, kMeshVertices, kChildTriangleIndices);
      } else {
        pkChildNode->m_eNodeType = NT_INTERNAL;
        Subdivide(pkChildNode, kMeshVertices, kChildTriangleIndices);
        
      }
    }
  
  }
}

void RFVoxelOctreeBuilder::UpdateLeafNodeDistanceValue(
    RFVoxelOctreeNode *pkLeafNode, 
    const std::vector<RFMath::RFVector3d> &kMeshVertices,
    const std::vector<uint> &kNodeTriangleIndices) {
  double fMinDist = numeric_limits<double>::max();

  for (uint v = 0; v < kNodeTriangleIndices.size(); v++) {
    RFVector3d kTriangleVerts[3];
    uint uiTriIndex = kNodeTriangleIndices[v];
    kTriangleVerts[0] = kMeshVertices[uiTriIndex];
    kTriangleVerts[1] = kMeshVertices[uiTriIndex + 1];
    kTriangleVerts[2] = kMeshVertices[uiTriIndex + 2];
    RFVector3d kNormal =
        VectorCross(kTriangleVerts[2] - kTriangleVerts[0], kTriangleVerts[1] - kTriangleVerts[0]);
    RFVector3d kClosestPoint = ClosestPointOnTriangle(kTriangleVerts, pkLeafNode->m_kWorldAabb.GetCenter());
    RFVector3d kDelta = kClosestPoint - pkLeafNode->m_kWorldAabb.GetCenter();
    double fSign = (VectorDot(kDelta, kNormal) < 0.0f) ? -1.0f : 1.0f;
    double fDist = VectorLength(kDelta);

    if (fDist < abs(fMinDist)) {
      fMinDist = fDist * fSign;
    }
  }

  pkLeafNode->m_fDistanceToSurface = fMinDist;
}

void RFVoxelOctreeBuilder::UpdateInternalEmptyLeafsSign(const RFVoxelOctreeNode *pkOctreeRoot,
                                                        RFVoxelOctreeNode *pkNode, const double fMinCoverage = 0.8) {
  if (pkNode == nullptr) return;

  if (pkNode->m_eNodeType == NT_LEAF) {
    return;  // The sign has already been update during octree building
  }

  if (pkNode->m_eNodeType == NT_INTERNAL) {
    for (uint i = 0; i < 8; i++) {
      UpdateInternalEmptyLeafsSign(pkOctreeRoot, pkNode->m_pkChildren[i], fMinCoverage);
    }
    return;
  }

  uint uiCoverage = 0;
  uint uiMisses = 0;
  uint uiMaxMisses = static_cast<uint>(m_kSampleDirections.size()) / 4;  // Stopping Heuristic

  for (uint j = 0; j < m_kSampleDirections.size(); j++) {

    RFRay3d kRay(pkNode->m_kWorldAabb.GetCenter(), m_kSampleDirections[j]);

    if (RayOctreeInterSection(kRay, pkOctreeRoot)) {
      uiCoverage++;
    } else {
      uiMisses++;
    }

    if (uiMisses >= uiMaxMisses) {
      break;
    }
  }

  double fCoverage = static_cast<double>(uiCoverage) / static_cast<double>(m_kSampleDirections.size());

  if (fCoverage >= fMinCoverage) {
    pkNode->m_fDistanceToSurface = -1.0f;
  } else {
    pkNode->m_fDistanceToSurface = 1.0f;
  }
}

void RFVoxelOctreeBuilder::UpdateOctreeStats(RFVoxelOctree *pkOctree) {
  if (!pkOctree->IsValid()) return;

  UpdateOctreeStats(pkOctree, pkOctree->m_pkRoot);
}

void RFVoxelOctreeBuilder::UpdateOctreeStats(RFVoxelOctree *pkOctree, RFVoxelOctreeNode *pkNode) {
  if (pkNode == nullptr) return;

  if (pkNode->m_eNodeType == NT_LEAF) {
    pkOctree->m_uiNumberOfLeafs++;
    ;
    return;
  }

  if (pkNode->m_eNodeType == NT_EMPTY_LEAF) {
    pkOctree->m_uiNumberOfEmptyLeafs++;
    return;
  }

  if (pkNode->m_eNodeType == NT_INTERNAL) {
    pkOctree->m_uiNumberOfInternalNodes++;

    for (uint i = 0; i < 8; i++) {
      UpdateOctreeStats(pkOctree, pkNode->m_pkChildren[i]);
    }
  }
}
