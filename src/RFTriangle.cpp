
#include "RFAxlPCH.h"
#include "RFTriangle.h"
#include <limits>

using namespace RFMath;

RFTriangle::RFTriangle():m_kCentroid(0.0f)
{
	m_kAabb = RFAABB3f(RFVector3f(std::numeric_limits<float>::max()),RFVector3f(std::numeric_limits<float>::min()));
}

RFTriangle::~RFTriangle()
{

}

