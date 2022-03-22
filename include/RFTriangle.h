#pragma once

#include "TRFVector3.h"
#include "TRFAABB3.h"

class RFTriangle
{

public:

	RFTriangle();
	~RFTriangle();

	RFMath::RFVector3f m_kVertices[3];
	RFMath::RFVector3f m_kFaceNormal;
	RFMath::RFVector3f m_kNormals[3];
	RFMath::RFVector3f m_kCentroid;
	RFMath::RFAABB3f m_kAabb;

};
