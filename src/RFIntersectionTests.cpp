
#include "RFIntersectionTests.h"
#include <math.h>
#include <limits>

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))


#define X 0
#define Y 1
#define Z 2

#define CROSS(dest,v1,v2)\
	dest[0]=v1[1]*v2[2]-v1[2]*v2[1];\
	dest[1]=v1[2]*v2[0]-v1[0]*v2[2];\
	dest[2]=v1[0]*v2[1]-v1[1]*v2[0]; 

#define DOT(v1,v2) (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2])

#define SUB(dest,v1,v2)\
	dest[0]=v1[0]-v2[0];\
	dest[1]=v1[1]-v2[1];\
	dest[2]=v1[2]-v2[2]; 

#define FINDMINMAX(x0,x1,x2,min,max)\
	min = max = x0;\
	if(x1<min) min=x1;\
	if(x1>max) max=x1;\
	if(x2<min) min=x2;\
	if(x2>max) max=x2;

/*======================== X-tests ========================*/

#define AXISTEST_X01(a, b, fa, fb)\
	p0 = a*v0[Y] - b*v0[Z];\
	p2 = a*v2[Y] - b*v2[Z];\
	if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;}\
	rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];\
	if(min>rad || max<-rad) return 0;

#define AXISTEST_X2(a, b, fa, fb)\
	p0 = a*v0[Y] - b*v0[Z];\
	p1 = a*v1[Y] - b*v1[Z];\
	if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;}\
	rad = fa * boxhalfsize[Y] + fb * boxhalfsize[Z];\
	if(min>rad || max<-rad) return 0;

/*======================== Y-tests ========================*/

#define AXISTEST_Y02(a, b, fa, fb)\
	p0 = -a*v0[X] + b*v0[Z];\
	p2 = -a*v2[X] + b*v2[Z];\
	if(p0<p2) {min=p0; max=p2;} else {min=p2; max=p0;}\
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];\
	if(min>rad || max<-rad) return 0;

#define AXISTEST_Y1(a, b, fa, fb)\
	p0 = -a*v0[X] + b*v0[Z];\
	p1 = -a*v1[X] + b*v1[Z];\
	if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;}\
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Z];\
	if(min>rad || max<-rad) return 0;
/*======================== Z-tests ========================*/

#define AXISTEST_Z12(a, b, fa, fb)\
	p1 = a*v1[X] - b*v1[Y];\
	p2 = a*v2[X] - b*v2[Y];\
	if(p2<p1) {min=p2; max=p1;} else {min=p1; max=p2;}\
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];\
	if(min>rad || max<-rad) return 0;


#define AXISTEST_Z0(a, b, fa, fb)\
	p0 = a*v0[X] - b*v0[Y];\
	p1 = a*v1[X] - b*v1[Y];\
	if(p0<p1) {min=p0; max=p1;} else {min=p1; max=p0;}\
	rad = fa * boxhalfsize[X] + fb * boxhalfsize[Y];\
	if(min>rad || max<-rad) return 0;


using namespace RFMath;
using namespace RFAxl;
using namespace std;

bool RFAxl::RayBoxIntersection(const RFMath::RFRay3d &kRay, RFMath::RFAABB3d &kAabb, float fTime, RFMath::RFVector2d &kHit)
{
	RFVector3d k0Aabb0 = kAabb.kMin * kRay.kInvDirection - kRay.kOod;
	RFVector3d k1Aabb0 = kAabb.kMax * kRay.kInvDirection - kRay.kOod;

	float tminAabb0 = max(0.0f, min(k0Aabb0.x, k1Aabb0.x));
	float tmaxAabb0 = max(k0Aabb0.x, k1Aabb0.x);

	tminAabb0 = max(tminAabb0, min(k0Aabb0.y, k1Aabb0.y));
	tmaxAabb0 = min(tmaxAabb0, max(k0Aabb0.y, k1Aabb0.y));
	tminAabb0 = max(tminAabb0, min(k0Aabb0.z, k1Aabb0.z));
	tmaxAabb0 = min(tmaxAabb0, max(k0Aabb0.z, k1Aabb0.z));
	tmaxAabb0 = min(tmaxAabb0,fTime);

	kHit.tX = tminAabb0;
	kHit.tY = tmaxAabb0;

	return (tmaxAabb0 >= tminAabb0);
}

bool RFAxl::RayBoxIntersection(const RFMath::RFRay3d &kRay, const RFMath::RFAABB3d &kAabb)
{
	auto origin = kRay.kOrigin;
    auto kInvDir = kRay.kInvDirection;

    auto kMin = kAabb.kMin;
    auto kMax = kAabb.kMax;

    double originX = origin.tX;
    double kInvDirX = kInvDir.tX;

    float l1   = (kMin.tX - originX) * kInvDirX;
	float l2   = (kMax.tX - originX) * kInvDirX;

	float tmin = min(l1,l2);
	float tmax = max(l1,l2);

    double originY = origin.tY;
    double kInvDirY = kInvDir.tY;
	l1   = (kMin.tY - originY) *  kInvDirY;
	l2   = (kMax.tY - originY) *  kInvDirY;

	tmin = max(min(l1,l2), tmin);
	tmax = min(max(l1,l2), tmax);

    double originZ = origin.tZ;
    double kInvDirZ = kInvDir.tZ;
	l1   = (kMin.tZ - originZ) * kInvDirZ;
	l2   = (kMax.tZ - originZ) * kInvDirZ;

	tmin = max(min(l1,l2), tmin);
	tmax = min(max(l1,l2), tmax);
	tmin = max(0.0f,tmin);

	return (tmax > tmin); 
}


int PlaneBoxOverlap(float normal[3], float vert[3], float maxbox[3])	// -NJMP-
{
	int q;
	float vmin[3], vmax[3], v;

	for (q = X; q <= Z; q++)
	{
		v = vert[q];					// -NJMP-

		if (normal[q] > 0.0f)
		{

			vmin[q] = -maxbox[q] - v;	// -NJMP-
			vmax[q] = maxbox[q] - v;	// -NJMP-
		}
		else
		{
			vmin[q] = maxbox[q] - v;	// -NJMP-
			vmax[q] = -maxbox[q] - v;	// -NJMP-
		}

	}

	if (DOT(normal, vmin) > 0.0f) return 0;	// -NJMP-
	if (DOT(normal, vmax) >= 0.0f) return 1;	// -NJMP-
	return 0;
}

int TriBoxOverlap(float boxcenter[3], float boxhalfsize[3], float triverts[3][3])
{

    /*    use separating axis theorem to test overlap between triangle and box */
	/*    need to test for overlap in these directions: */
	/*    1) the {x,y,z}-directions (actually, since we use the AABB of the triangle */
	/*       we do not even need to test these) */
	/*    2) normal of the triangle */
	/*    3) crossproduct(edge from tri, {x,y,z}-directin) */
	/*       this gives 3x3=9 more tests */
	float v0[3],v1[3],v2[3];

	//   float axis[3];
	float min,max,p0,p1,p2,rad,fex,fey,fez;		// -NJMP- "d" local variable removed
	float normal[3],e0[3],e1[3],e2[3];

	/* This is the fastest branch on Sun */
	/* move everything so that the boxcenter is in (0,0,0) */
	SUB(v0,triverts[0],boxcenter);
	SUB(v1,triverts[1],boxcenter);
	SUB(v2,triverts[2],boxcenter);

	/* compute triangle edges */
	SUB(e0,v1,v0);      /* tri edge 0 */
	SUB(e1,v2,v1);      /* tri edge 1 */
	SUB(e2,v0,v2);      /* tri edge 2 */

	/* Bullet 3:  */
	/*  test the 9 tests first (this was faster) */
	fex = fabsf(e0[X]);
	fey = fabsf(e0[Y]);
	fez = fabsf(e0[Z]);

	AXISTEST_X01(e0[Z], e0[Y], fez, fey);
	AXISTEST_Y02(e0[Z], e0[X], fez, fex);
	AXISTEST_Z12(e0[Y], e0[X], fey, fex);

	fex = fabsf(e1[X]);
	fey = fabsf(e1[Y]);
	fez = fabsf(e1[Z]);

	AXISTEST_X01(e1[Z], e1[Y], fez, fey);
	AXISTEST_Y02(e1[Z], e1[X], fez, fex);
	AXISTEST_Z0(e1[Y], e1[X], fey, fex);

	fex = fabsf(e2[X]);
	fey = fabsf(e2[Y]);
	fez = fabsf(e2[Z]);
	AXISTEST_X2(e2[Z], e2[Y], fez, fey);
	AXISTEST_Y1(e2[Z], e2[X], fez, fex);
	AXISTEST_Z12(e2[Y], e2[X], fey, fex);

	/* Bullet 1: */
	/*  first test overlap in the {x,y,z}-directions */
	/*  find min, max of the triangle each direction, and test for overlap in */
	/*  that direction -- this is equivalent to testing a minimal AABB around */
	/*  the triangle against the AABB */
	/* test in X-direction */
	FINDMINMAX(v0[X],v1[X],v2[X],min,max);
	if(min>boxhalfsize[X] || max<-boxhalfsize[X]) return 0;

	/* test in Y-direction */
	FINDMINMAX(v0[Y],v1[Y],v2[Y],min,max);
	if(min>boxhalfsize[Y] || max<-boxhalfsize[Y]) return 0;

	/* test in Z-direction */
	FINDMINMAX(v0[Z],v1[Z],v2[Z],min,max);
	if(min>boxhalfsize[Z] || max<-boxhalfsize[Z]) return 0;

	/* Bullet 2: */
	/*  test if the box intersects the plane of the triangle */
	/*  compute plane equation of triangle: normal*x+d=0 */
	CROSS(normal,e0,e1);

	if(!PlaneBoxOverlap(normal,v0,boxhalfsize)) return 0;	// -NJMP-

	return 1;   /* box and triangle overlaps */
}

bool RFAxl::TriangleAabbIntersects(RFMath::RFVector3d kTriangleVertices[3], RFMath::RFAABB3d kAabb)
{
	float kTriVerts[3][3];
	float kBoxCenter[3];
	float kBoxHalfSize[3];

    auto center = kAabb.GetCenter();
	kBoxCenter[0] = center.tX;
	kBoxCenter[1] = center.tY;
	kBoxCenter[2] = center.tZ;

	kBoxHalfSize[0] = kAabb.GetWidth() * 0.5f;
	kBoxHalfSize[1] = kAabb.GetHeight()* 0.5f;
	kBoxHalfSize[2] = kAabb.GetDepth() * 0.5f;

	for(unsigned int i = 0; i < 3; i++)
	{
      auto v = kTriangleVertices[i];
      kTriVerts[i][0] = v.tX;
      kTriVerts[i][1] = v.tY;
      kTriVerts[i][2] = v.tZ;
	}

	return (TriBoxOverlap(kBoxCenter,kBoxHalfSize,kTriVerts) > 0);
}

bool RFAxl::RayOctreeInterSection(const RFMath::RFRay3d &kRay, const RFVoxelOctreeNode *pkNode)
{
	if(pkNode == nullptr) return false;

	if(pkNode->m_eNodeType == NT_LEAF)
	{
		return RayBoxIntersection(kRay, pkNode->m_kWorldAabb);
	}

	if(pkNode->m_eNodeType == NT_INTERNAL)
	{
		if(RayBoxIntersection(kRay,pkNode->m_kWorldAabb))
		{
			for(uint i = 0; i < 8 ; i++)
			{
				if(RayOctreeInterSection(kRay,pkNode->m_pkChildren[i]))
				{
					return true;
				}
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}

float  RFSaturate(float f)
{
	return max(0.0f, min(f, 1.0f));
}

RFMath::RFVector3d RFAxl::ClosestPointOnTriangle(RFMath::RFVector3d kTriangleVertices[3], const RFMath::RFVector3d &kPos)
{
	RFVector3d edge0 = kTriangleVertices[1] - kTriangleVertices[0];
	RFVector3d edge1 = kTriangleVertices[2] - kTriangleVertices[0];
	RFVector3d v0    = kTriangleVertices[0] - kPos;

	double a = VectorDot(edge0, edge0);
	double b = VectorDot(edge0, edge1);
	double c = VectorDot(edge1, edge1);
	double d = VectorDot(edge0, v0);
	double e = VectorDot(edge1, v0);

	double det = a*c - b*b;
	double s   = b*e - c*d;
	double t   = b*d - a*e;

	if (s + t < det)
	{
		if (s < 0.0f)
		{
			if (t < 0.0f)
			{
				if (d < 0.0f)
				{
					s = RFSaturate(-d / a);
					t = 0.0f;
				}
				else
				{
					s = 0.0f;
					t = RFSaturate(-e / c);
				}
			}
			else
			{
				s = 0.0f;
				t = RFSaturate(-e / c);
			}
		}
		else if (t < 0.0f)
		{
			s = RFSaturate(-d / a);
			t = 0.f;
		}
		else
		{
			float invDet = 1.0f / det;
			s *= invDet;
			t *= invDet;
		}
	}
	else
	{
		if (s < 0.0f)
		{
			float tmp0 = b + d;
			float tmp1 = c + e;
			if (tmp1 > tmp0)
			{
				float numer = tmp1 - tmp0;
				float denom = a - 2.0f*b + c;
				s = RFSaturate(numer / denom);
				t = 1.0f - s;
			}
			else
			{
				t = RFSaturate(-e / c);
				s = 0.0f;
			}
		}
		else if (t < 0.0f)
		{
			if (a + d > b + e)
			{
				float numer = c + e - b - d;
				float denom = a - 2.0f*b + c;
				s = RFSaturate(numer / denom);
				t = 1.0f - s;
			}
			else
			{
				s = RFSaturate(-e / c);
				t = 0.0f;
			}
		}
		else
		{
			float numer = c + e - b - d;
			float denom = a - 2.0f*b + c;
			s = RFSaturate(numer / denom);
			t = 1.0f - s;
		}
	}
	return kTriangleVertices[0] + s * edge0 + t * edge1;
}
