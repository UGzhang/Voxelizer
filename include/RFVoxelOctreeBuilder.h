#pragma once
#include "RFVoxelOctree.h"
#include <vector>

namespace RFAxl
{

	class RFVoxelOctreeBuilder
	{
	public:
		RFVoxelOctreeBuilder();
		~RFVoxelOctreeBuilder();

		RFVoxelOctree *CreateOctree(const std::vector<RFMath::RFVector3d> &kMeshVertices,
                                    const RFMath::RFAABB3d kMeshAabb,
									const int kOctreeDim,
                                    const double fMinCoverage = 0.9,
                                    const double fBorderSize = 0.0);

	private:

		void Subdivide(RFVoxelOctreeNode *pkParentNode, const std::vector<RFMath::RFVector3d> &kMeshVertices, const std::vector<uint> &kNodeTriangleIndices);
		void UpdateLeafNodeDistanceValue(RFVoxelOctreeNode *pkLeafNode, const std::vector<RFMath::RFVector3d> &kMeshVertices, const std::vector<uint> &kNodeTriangleIndices);
		void UpdateInternalEmptyLeafsSign(const RFVoxelOctreeNode *pkOctreeRoot, RFVoxelOctreeNode *pkNode, const double fMinCoverage);
		void UpdateOctreeStats(RFVoxelOctree *pkOctree);
		void UpdateOctreeStats(RFVoxelOctree *pkOctree, RFVoxelOctreeNode *pkNode);

		std::vector<RFMath::RFVector3d> m_kSampleDirections; // Use
		RFVoxelOctree *m_pkVoxelOctree;
	};

}