
#include "RFVoxelOctree.h"

using namespace RFAxl;

// cout face
static uint64 k = 1; 

void RFVoxelOctreeNode::GetNodeVerticeFace(
    std::vector<RFMath::RFVector3d> &kVertices, std::vector<RFMath::RFVector3ui> &kFaces) {
  //       Y
  //	   2-------1     
  //	  /|      /|     
  //	 / |     / |
  //	7--|----8  |
  //	|  4----|--3  X
  //	| /     | /
  //	5-------6
  //   Z

  using namespace RFMath;
  
  RFVector3d v4 = m_kWorldAabb.kMin;
  RFVector3d v8 = m_kWorldAabb.kMax;
  
  RFVector3d v3 = {v4.x + m_kWorldAabb.GetWidth(), v4.y, v4.z};
  RFVector3d v2 = {v4.x, v4.y + m_kWorldAabb.GetHeight(), v4.z};
  RFVector3d v1 = {v2.x + m_kWorldAabb.GetWidth(), v2.y, v2.z};
		   
  RFVector3d v7 = {v8.x - m_kWorldAabb.GetWidth(), v8.y, v8.z};
  RFVector3d v6 = {v8.x, v8.y - m_kWorldAabb.GetHeight(), v8.z};
  RFVector3d v5 = {v6.x - m_kWorldAabb.GetWidth(), v6.y, v6.z};

  kVertices.push_back(v1);
  kVertices.push_back(v2);
  kVertices.push_back(v3);
  kVertices.push_back(v4);
  kVertices.push_back(v5);
  kVertices.push_back(v6);
  kVertices.push_back(v7);
  kVertices.push_back(v8);

  //// back
  //RFVector3ui f1 = {k, k + 2, k + 3};
  //RFVector3ui f2 = {k, k + 3, k + 1};
  //// bottom
  //RFVector3ui f3 = {k + 3, k + 2, k + 5};
  //RFVector3ui f4 = {k + 3, k + 5, k + 4};
  //// right
  //RFVector3ui f5 = {k + 2, k, k + 7};
  //RFVector3ui f6 = {k + 2, k + 7, k + 5};
  //// top
  //RFVector3ui f7 = {k, k + 1, k + 6};
  //RFVector3ui f8 = {k, k + 6, k + 7};
  //// left
  //RFVector3ui f9 = {k + 1, k + 3, k + 4};
  //RFVector3ui f10 = {k + 1, k + 4, k + 6};
  //// front
  //RFVector3ui f11 = {k + 4, k + 5, k + 7};
  //RFVector3ui f12 = {k + 4, k + 7, k + 6};


    // back
  RFVector3ui f1(k, k + 2, k + 3);
  RFVector3ui f2(k, k + 3, k + 1);
  // bottom	  
  RFVector3ui f3(k + 3, k + 2, k + 5);
  RFVector3ui f4(k + 3, k + 5, k + 4);
  // right	  
  RFVector3ui f5(k + 2, k, k + 7);
  RFVector3ui f6(k + 2, k + 7, k + 5);
  // top	  
  RFVector3ui f7(k, k + 1, k + 6);
  RFVector3ui f8(k, k + 6, k + 7);
  // left	  
  RFVector3ui f9(k + 1, k + 3, k + 4);
  RFVector3ui f10(k + 1, k + 4, k + 6);
  // front	  
  RFVector3ui f11(k + 4, k + 5, k + 7);
  RFVector3ui f12(k + 4, k + 7, k + 6);

  //push back faces
  kFaces.push_back(f1);
  kFaces.push_back(f2);
  kFaces.push_back(f3);
  kFaces.push_back(f4);
  kFaces.push_back(f5);
  kFaces.push_back(f6);
  kFaces.push_back(f7);
  kFaces.push_back(f8);
  kFaces.push_back(f9);
  kFaces.push_back(f10);
  kFaces.push_back(f11);
  kFaces.push_back(f12);

  k += 8;

}



RFVoxelOctreeNode::RFVoxelOctreeNode() :
m_eNodeType(NT_INTERNAL),
m_fDistanceToSurface(0.0f)
{
	for (uint i = 0; i < 8; i++)
	{
		m_pkChildren[i] = nullptr;
	}
}

RFVoxelOctreeNode::~RFVoxelOctreeNode()
{
	for (unsigned int i = 0; i < 8; i++)
	{
		delete m_pkChildren[i];
	}
}


RFVoxelOctree::RFVoxelOctree() : 
m_pkRoot(nullptr),
m_fVoxelSize(1.0f), 
m_kDataDimension(0), 
m_kOctreeOrigin(0.0f),
m_uiOctreeDim(0), 
m_uiOctreeDepth(0), 
m_uiNumberOfNodes(0), 
m_uiNumberOfLeafs(0), 
m_uiNumberOfEmptyLeafs(0), 
m_uiNumberOfInternalNodes(0)
{

}

RFVoxelOctree::~RFVoxelOctree()
{
	//int order;
 // size = (size - 1) >> (0);
 // order = -1;
 // do {
 //   size >>= 1;
 //   order++;
 // } while (size);

	delete m_pkRoot;
}

bool RFVoxelOctree::IsValid() const
{
	return m_pkRoot != nullptr;
}

uint RFVoxelOctree::GetDepth() const
{
	return static_cast<uint>(std::log2(m_uiOctreeDim));
}


float RFVoxelOctree::GetVoxelSize() const
{
	return m_fVoxelSize;
}

RFMath::RFVector3d RFVoxelOctree::GetVoxelCornerPosition() const
{
	return m_pkRoot->m_kWorldAabb.kMin;
}
