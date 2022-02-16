#pragma once

namespace RFMath
{
	template <typename T>
	struct TRFVector3
	{
		// Typedefs.
		typedef TRFVector3<T> type;
		typedef T value_type;

		// Data.
		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T tX, tY, tZ; };
			struct { T tR, tG, tB; };
		};

		// Constructors.
		inline TRFVector3();
		inline TRFVector3(const TRFVector3<T>& kVec);
		explicit inline TRFVector3(T tValue);
		inline TRFVector3(T tX, T tY, T tZ);
		explicit inline TRFVector3(T tData[3]);

		// Conversion constructors.	
		template <typename U>
		explicit inline TRFVector3(const TRFVector3<U>& kVec);		

		// Convenience constructors.
		inline TRFVector3(const TRFVector2<T>& kVec, T tZ);
		inline TRFVector3(T tX, const TRFVector2<T>& kVec);

		// Access operators.
		inline T& operator[](int i);
		inline T operator[](int i) const;

		// Data pointer access.
		inline T* Data();
		inline const T* Data() const;

		// As-vectors.
		inline TRFVector2<T> AsVector2() const;

		// Unary arithmetic operators.
		inline TRFVector3<T>& operator=(const TRFVector3<T>& kVec);
		
		inline TRFVector3<T>& operator+=(T tValue);
		inline TRFVector3<T>& operator+=(const TRFVector3<T>& kVec);
		
		inline TRFVector3<T>& operator-=(T tValue);
		inline TRFVector3<T>& operator-=(const TRFVector3<T>& kVec);
		
		inline TRFVector3<T>& operator*=(T tValue);
		inline TRFVector3<T>& operator*=(const TRFVector3<T>& kVec);
		
		inline TRFVector3<T>& operator/=(T tValue);
		inline TRFVector3<T>& operator/=(const TRFVector3<T>& kVec);
	};

	// Binary arithmetic operators.
	template <typename T>
	inline TRFVector3<T> operator+(const TRFVector3<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector3<T> operator+(T tValue, const TRFVector3<T>& kVec);
	template <typename T> 
	inline TRFVector3<T> operator+(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);

	template <typename T>
	inline TRFVector3<T> operator-(const TRFVector3<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector3<T> operator-(T tValue, const TRFVector3<T>& kVec);
	template <typename T> 
	inline TRFVector3<T> operator-(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);

	template <typename T>
	inline TRFVector3<T> operator*(const TRFVector3<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector3<T> operator*(T tValue, const TRFVector3<T>& kVec);
	template <typename T> 
	inline TRFVector3<T> operator*(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);

	template <typename T>
	inline TRFVector3<T> operator/(const TRFVector3<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector3<T> operator/(T tValue, const TRFVector3<T>& kVec);
	template <typename T> 
	inline TRFVector3<T> operator/(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);

	// Unary constant operators.
	template <typename T> 
	inline TRFVector3<T> operator-(const TRFVector3<T>& kVec);

	// Binary operators.
	template <typename T> 
	inline bool operator==(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);
	template <typename T>
	inline bool operator!=(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);	

	// Streaming.
 	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFVector3<T>& kVec);

	// Geometric functions.
	template <typename T>
	inline T VectorAngleBetweenNormals(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);
	template <typename T>
	inline T VectorAngleBetweenVectors(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);
	template <typename T>
	inline TRFVector3<T> VectorClamp(const TRFVector3<T>& kVec, T tMin, T tMax);
	template <typename T>
	inline TRFVector3<T> VectorClampLength(const TRFVector3<T>& kVec, T tMinLength, T tMaxLength);
	template <typename T>
	inline TRFVector3<T> VectorCross(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);
	template <typename T>
	inline T VectorDot(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1);
	template <typename T>
	inline TRFVector3<T> VectorLerp(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1, T tT);
	template <typename T>
	inline TRFVector3<T> VectorSmoothStep(const TRFVector3<T>& kVec0, const TRFVector3<T>& kVec1, T tT);
	template <typename T>
	inline T VectorLength(const TRFVector3<T>& kVec);
	template <typename T>
	inline T VectorLengthSquared(const TRFVector3<T>& kVec);
	template <typename T>
	inline TRFVector3<T> VectorReciprocal(const TRFVector3<T>& kVec);
	template <typename T>
	inline T VectorReciprocalLength(const TRFVector3<T>& kVec);
	template <typename T>
	inline TRFVector3<T> VectorNormalize(const TRFVector3<T>& kVec);	
	template <typename T>
	inline TRFVector3<T> VectorReflect(const TRFVector3<T>& kIncident, const TRFVector3<T>& kNormal);
	template <typename T>
	inline TRFVector3<T> VectorRefract(const TRFVector3<T>& kIncident, const TRFVector3<T>& kNormal, T tRefractIndex);

	// Utility.
	template <typename T>
	void VectorComputeExtremesV(uint uiCount, const TRFVector3<T>* pkVectors, TRFVector3<T>& kMin, TRFVector3<T>& kMax);
	template <typename T>
	uint VectorIndexOfMaxAbsComponent(const TRFVector3<T>& kVec);
	template <typename T>
	inline TRFVector3<T> VectorFloor(const TRFVector3<T>& kVec);
	template <typename T>
	inline TRFVector3<T> VectorAbs(const TRFVector3<T>& kVec);
	template <typename T>
	inline TRFVector3<T> VectorMin(const TRFVector3<T>& kVec);
	template <typename T>
	inline TRFVector3<T> VectorMax(const TRFVector3<T>& kVec);

	// Size types.
	typedef TRFVector3<float> RFVector3f;
	typedef TRFVector3<double> RFVector3d;
	typedef TRFVector3<int8> RFVector3i8;
	typedef TRFVector3<uint8> RFVector3ui8;
	typedef TRFVector3<int16> RFVector3i16;
	typedef TRFVector3<uint16> RFVector3ui16;
	typedef TRFVector3<int32> RFVector3i;
	typedef TRFVector3<uint32> RFVector3ui;
	typedef TRFVector3<int64> RFVector3i64;
	typedef TRFVector3<uint64> RFVector3ui64;
}

#include "TRFVector3.inl"
