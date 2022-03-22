#pragma once


#include <fstream>
#include <vector>
#include "TRFVectors.h"
#include "TRFVector2.h"
#include "TRFVector3.h"
#include "TRFAABB3.h"

namespace RFAxl
{
	enum ERFVoxelOctreeNodeType{ NT_INTERNAL, NT_EMPTY_LEAF, NT_LEAF };

	class RFVoxelOctreeNode
	{
	public:
		RFVoxelOctreeNode();
		~RFVoxelOctreeNode();

		RFVoxelOctreeNode *m_pkChildren[8];
		RFMath::RFAABB3i m_kBuildAabb;
		RFMath::RFAABB3d m_kWorldAabb;
		ERFVoxelOctreeNodeType m_eNodeType;
		double m_fDistanceToSurface;


		// 2022.2.10 
		// get eight point from one noede(cube)
        void GetNodeVerticeFace(std::vector<RFMath::RFVector3d> &kVertices, std::vector<RFMath::RFVector3ui> &kFaces);

	};

	struct RFVoxelOctree
	{
		RFVoxelOctree();
		~RFVoxelOctree();

		bool IsValid() const;
		uint GetDepth() const;
		float GetVoxelSize() const;
		RFMath::RFVector3d GetVoxelCornerPosition() const;

		// Octree Data 
		RFVoxelOctreeNode *m_pkRoot;

		// Stats
		RFMath::RFVector3i m_kDataDimension; 
		RFMath::RFVector3d m_kOctreeOrigin;  // The lower left corner
		double m_fVoxelSize;
		uint m_uiOctreeDim;
		uint m_uiOctreeDepth;
		uint m_uiNumberOfNodes;
		uint m_uiNumberOfLeafs;
		uint m_uiNumberOfEmptyLeafs;
		uint m_uiNumberOfInternalNodes;
	};

}