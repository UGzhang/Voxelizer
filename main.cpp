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

using namespace std;
using namespace RFMath;
using namespace RFAxl;

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
    //RFVector3f kVert = pkNode->m_kWorldAabb.GetCenter();
    //kVertices.push_back(kVert);

    //float fDist = pkNode->m_fDistanceToSurface;
    //float fVal = -fDist * 200.0f;
    //uint kColor = static_cast<uint>(min(255.0f, max(0.0f, fVal)));
    //kColors.push_back(RFVector3ui(kColor));
    return;
  }

  if (pkNode->m_eNodeType == NT_EMPTY_LEAF) {
    if (pkNode->m_fDistanceToSurface < 0.0f) {

        pkNode->GetNodeVerticeFace(kVertices, kFaces);
     /* RFVector3f kVert = pkNode->m_kWorldAabb.GetCenter();

      if (pkNode->m_kBuildAabb.GetWidth() > 1) {
        kVertices.push_back(kVert);
        kColors.push_back(RFVector3ui(0, 255, 0));
      } else {
        kVertices.push_back(kVert);
        kColors.push_back(RFVector3ui(0, 0, 255));
      }*/
    }

    return;
  }

  if (pkNode->m_eNodeType == NT_INTERNAL) {
    for (uint i = 0; i < 8; i++) {
      TraverseOctree(pkNode->m_pkChildren[i], kVertices, kFaces);
    }
  }
}

int main(int argc, char **argv) {
  vector<RFVector3d> kVertices;
  vector<RFVector3i> kFaces;
  vector<RFVector3d> kMeshVertices;  // stored triangle wise (v0,v1,v2)...

   //fstream kIn( "../Armadillo.obj" );
  fstream kIn("E:\\data\\temp\\sphere.obj");

  if (!kIn) {
    cout << "unable to load mesh" << endl;
  }

  string kString;
  string kValues[3];


  while (!kIn.eof()) {
    kIn >> kString;
    if (kString == g_kVert) {
      for (int i = 0; i < 3; ++i) {
        kIn >> kValues[i] ;
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
    // notice the notorious obj index from 1!!!!
    kMeshVertices.push_back(kVertices[kFace.tX - 1]);
    kMeshVertices.push_back(kVertices[kFace.tY - 1]);
    kMeshVertices.push_back(kVertices[kFace.tZ - 1]);
  }

  RFAABB3d kAabb;
  kAabb.kMax = RFVectors3d::MIN;
  kAabb.kMin = RFVectors3d::MAX;

  for (uint i = 0; i < static_cast<uint>(kMeshVertices.size()); ++i) {
    RFVector3d &kVert = kMeshVertices[i];

    for (uint j = 0; j < 3; ++j) {
      kAabb.kMin[j] = min(kAabb.kMin[j], kVert[j]);
      kAabb.kMax[j] = max(kAabb.kMax[j], kVert[j]);
    }
  }

  ofstream kOut("Output.obj");

  RFVoxelOctreeBuilder kVoxelBuilder;
  //RFVoxelOctree *pkVoxelOctree = kVoxelBuilder.CreateOctree(kMeshVertices, kAabb, 0.01, 0.9);
  RFVoxelOctree *pkVoxelOctree = kVoxelBuilder.CreateOctree(kMeshVertices, kAabb, static_cast<uint32>(60));
  //RFVoxelOctree *pkVoxelOctree = kVoxelBuilder.CreateOctree(kMeshVertices, kAabb, 0.01f, 0.8f);

  std::vector<RFVector3d> kOutputVertices;
  std::vector<RFVector3ui> kOutFaces;

  TraverseOctree(pkVoxelOctree->m_pkRoot, kOutputVertices, kOutFaces);

  //kOut << "ply" << endl;
  //kOut << "format ascii 1.0" << endl;
  //kOut << "comment made by CG alexandra" << endl;
  //kOut << "element vertex " << kOutputVertices.size() << endl;
  //kOut << "property float x" << endl;
  //kOut << "property float y" << endl;
  //kOut << "property float z" << endl;
  //kOut << "property uchar red" << endl;
  //kOut << "property uchar green" << endl;
  //kOut << "property uchar blue" << endl;
  //kOut << "end_header" << endl;

  for (auto &vert : kOutputVertices) {
    kOut << "v"
         << " " << vert.tX << " " << vert.tY << " " << vert.tZ << endl;
  }

  for (auto &face : kOutFaces) {
    kOut << "f"
         << " "<< face.tX << " " << face.tY << " " << face.tZ << endl;
  }

  /*for (uint i = 0; i < static_cast<uint>(kOutputVertices.size()); ++i) {

    RFVector3f &kV0 = kOutputVertices[i];
    RFVector3ui &kFace = kOutFaces[i];

    kOut << kV0.tX << " " << kV0.tY << " " << kV0.tZ << " " << kFace.tX << " " << kFace.tY << " "
         << kFace.tZ << endl;
    
  }*/

  kOut.close();
  return 1;
}