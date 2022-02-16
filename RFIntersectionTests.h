#pragma once

#include "TRFRay3.h"
#include "RFVoxelOctree.h"

namespace RFAxl
{
	bool RayBoxIntersection(const RFMath::RFRay3d &kRay, RFMath::RFAABB3d &kAabb, float fTime, RFMath::RFVector2d &kHit);
	bool RayBoxIntersection(const RFMath::RFRay3d &kRay, const RFMath::RFAABB3d &kAabb);
	bool TriangleAabbIntersects(RFMath::RFVector3d kTriangleVertices[3], RFMath::RFAABB3d kAabb);
	bool RayOctreeInterSection(const RFMath::RFRay3d &kRay, const RFVoxelOctreeNode *pkNode);
	RFMath::RFVector3d ClosestPointOnTriangle(RFMath::RFVector3d kTriangleVertices[3], const RFMath::RFVector3d &kPos);
}
