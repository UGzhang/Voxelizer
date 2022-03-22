// git add -u 
// git commit -m ""
// git reset -- build/*
// git push origin main
//-------------------------------------------------------------------------
// peter.trier@alexandra.dk
// Used it carefully and don't harm children or animals license
//-------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "RFVoxelOctree.h"
#include "RFVoxelOctreeBuilder.h"
#include "Instrumentor.h"

using namespace std;
using namespace RFMath;
using namespace RFAxl;


#define USE_TIMEIT 1

#if USE_TIMEIT
#define TIMEIT() InstrumentationTimer timer(__FUNCTION__);
#define TIMEITNAME(name) InstrumentationTimer timer(name);
#else
#define TIMEIT()
#endif

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

string g_kVert("v");
string g_kFace("f");

void TraverseOctree(
    RFVoxelOctreeNode *pkNode, 
    std::vector<RFVector3d> &kVertices,
    std::vector<RFVector3ui> &kFaces
) {
  if (pkNode == nullptr) return;

  if (pkNode->m_eNodeType == NT_LEAF) {
    pkNode->GetNodeVerticeFace(kVertices, kFaces);
    return;
  }

  if (pkNode->m_eNodeType == NT_EMPTY_LEAF) {
    if (pkNode->m_fDistanceToSurface < 0.0f) {
        pkNode->GetNodeVerticeFace(kVertices, kFaces);
    }
    return;
  }

  if (pkNode->m_eNodeType == NT_INTERNAL) {
    for (uint i = 0; i < 8; i++) {
      TraverseOctree(pkNode->m_pkChildren[i], kVertices, kFaces);
    }
  }
}

void loadMesh(vector<RFVector3d> &kMeshVertices, RFAABB3d &kAabb, std::string filePath) {
  TIMEIT();
  vector<RFVector3d> kVertices;
  vector<RFVector3i> kFaces;

  fstream kIn( filePath );
  //fstream kIn("E:\\data\\temp\\cube.obj");

  if (!kIn) {
    cout << "unable to load mesh" << endl;
  }

  string kString;
  string kValues[3];


  while (!kIn.eof()) {
    kIn >> kString;
    if (kString == g_kVert) {
      for (int i = 0; i < 3; ++i) {
        kIn >> kValues[i];
      }
      kVertices.push_back(RFVector3d(static_cast<double>(atof(kValues[0].c_str())),
                                     static_cast<double>(atof(kValues[1].c_str())),
                                     static_cast<double>(atof(kValues[2].c_str()))));
    }

    if (kString == g_kFace) {
      for (int i = 0; i < 3; ++i) {
        kIn >> kValues[i];
      }
      kFaces.push_back(
          RFVector3i(atoi(kValues[0].c_str()), atoi(kValues[1].c_str()), atoi(kValues[2].c_str())));
    }
  }

  kIn.close();


  // Create the vertex list
  for (uint i = 0; i < static_cast<uint>(kFaces.size()); ++i) {
    RFVector3i &kFace = kFaces[i];
    // notice the notorious obj index from 1!
    kMeshVertices.push_back(kVertices[kFace.tX - 1]);
    kMeshVertices.push_back(kVertices[kFace.tY - 1]);
    kMeshVertices.push_back(kVertices[kFace.tZ - 1]);
  }


  kAabb.kMax = RFVectors3d::MIN;
  kAabb.kMin = RFVectors3d::MAX;

  for (uint i = 0; i < static_cast<uint>(kMeshVertices.size()); ++i) {
    RFVector3d &kVert = kMeshVertices[i];

    for (uint j = 0; j < 3; ++j) {
      kAabb.kMin[j] = min(kAabb.kMin[j], kVert[j]);
      kAabb.kMax[j] = max(kAabb.kMax[j], kVert[j]);
    }
  }
  cout << "Load obj file successfully" << endl;
}


void outputOBJ(std::vector<RFVector3d> &kOutputVertices, std::vector<RFVector3ui> &kOutFaces) {
  TIMEIT();
  ofstream kOut("Output.obj");
  for (auto &vert : kOutputVertices) {
    kOut << "v"
         << " " << vert.tX << " " << vert.tY << " " << vert.tZ << endl;
  }

  for (auto &face : kOutFaces) {
    kOut << "f"
         << " " << face.tX << " " << face.tY << " " << face.tZ << endl;
  }

  kOut.close();
  cout << "Output obj file successfully" << endl;
}

int main() {
  Instrumentor::Get().BeginSession("timeAnalysis");
  vector<RFVector3d> kMeshVertices;
  RFAABB3d kAabb;
  std::vector<RFVector3d> kOutputVertices;
  std::vector<RFVector3ui> kOutFaces;

  std::string filePath = "../Armadillo.obj";
  loadMesh(kMeshVertices, kAabb, filePath);

  {
  TIMEITNAME("BuildOctree");
  cout << "Generate octree" << endl;
  RFVoxelOctreeBuilder kVoxelBuilder;
  RFVoxelOctree *pkVoxelOctree = kVoxelBuilder.CreateOctree(kMeshVertices, kAabb, 60);
  TraverseOctree(pkVoxelOctree->m_pkRoot, kOutputVertices, kOutFaces);
  cout << "Build octree successfully" << endl;
  }
  
  outputOBJ(kOutputVertices, kOutFaces);

  Instrumentor::Get().EndSession();

  return 1;
}