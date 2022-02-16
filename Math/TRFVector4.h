#pragma once

namespace RFMath
{
	template <typename T>
	struct TRFVector4
	{
		// Typedefs.
		typedef TRFVector4<T> type;
		typedef T value_type;

		// Data.
		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T tX, tY, tZ, tW; };
			struct { T tR, tG, tB, tA; };
		};

		// Constructors.
		inline TRFVector4();
		inline TRFVector4(const TRFVector4<T>& kVec);
		explicit inline TRFVector4(T tValue);
		inline TRFVector4(T tX, T tY, T tZ, T tW);
		explicit inline TRFVector4(T tData[4]);

		// Conversion constructors.
		template <typename U>
		explicit inline TRFVector4(const TRFVector4<U>& kVec);

		// Convenience constructors.
		inline TRFVector4(const TRFVector2<T>& kVec, T tZ, T tW);
		inline TRFVector4(T tX, const TRFVector2<T>& kVec, T tW);
		inline TRFVector4(T tX, T tY, const TRFVector2<T>& kVec);
		inline TRFVector4(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);
		inline TRFVector4(const TRFVector3<T>& kVec, T tW);
		inline TRFVector4(T tX, const TRFVector3<T>& kVec);

		// Access operators.
		inline T& operator[](int i);
		inline T operator[](int i) const;

		// Data pointer access.
		inline T* Data();
		inline const T* Data() const;

		// As-vectors.
		inline TRFVector2<T> AsVector2() const;
		inline TRFVector3<T> AsVector3() const;

		// Unary arithmetic operators.
		inline TRFVector4<T>& operator=(const TRFVector4<T>& kVec);
		
		inline TRFVector4<T>& operator+=(T tValue);
		inline TRFVector4<T>& operator+=(const TRFVector4<T>& kVec);
		
		inline TRFVector4<T>& operator-=(T tValue);
		inline TRFVector4<T>& operator-=(const TRFVector4<T>& kVec);
		
		inline TRFVector4<T>& operator*=(T tValue);
		inline TRFVector4<T>& operator*=(const TRFVector4<T>& kVec);
		
		inline TRFVector4<T>& operator/=(T tValue);
		inline TRFVector4<T>& operator/=(const TRFVector4<T>& kVec);
	};

	// Binary arithmetic operators.
	template <typename T>
	inline TRFVector4<T> operator+(const TRFVector4<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector4<T> operator+(T tValue, const TRFVector4<T>& kVec);
	template <typename T> 
	inline TRFVector4<T> operator+(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);

	template <typename T>
	inline TRFVector4<T> operator-(const TRFVector4<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector4<T> operator-(T tValue, const TRFVector4<T>& kVec);
	template <typename T> 
	inline TRFVector4<T> operator-(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);

	template <typename T>
	inline TRFVector4<T> operator*(const TRFVector4<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector4<T> operator*(T tValue, const TRFVector4<T>& kVec);
	template <typename T> 
	inline TRFVector4<T> operator*(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);

	template <typename T>
	inline TRFVector4<T> operator/(const TRFVector4<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector4<T> operator/(T tValue, const TRFVector4<T>& kVec);
	template <typename T> 
	inline TRFVector4<T> operator/(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);

	// Unary constant operators.
	template <typename T> 
	inline TRFVector4<T> operator-(const TRFVector4<T>& kVec);

	// Binary operators.
	template <typename T> 
	inline bool operator==(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);
	template <typename T>
	inline bool operator!=(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);	

	// Streaming.
 	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFVector4<T>& kVec);

	// Geometric functions.
	template <typename T>
	inline T VectorAngleBetweenNormals(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);
	template <typename T>
	inline T VectorAngleBetweenVectors(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);
	template <typename T>
	inline TRFVector4<T> VectorClamp(const TRFVector4<T>& kVec, T tMin, T tMax);
	template <typename T>
	inline TRFVector4<T> VectorClampLength(const TRFVector4<T>& kVec, T tMinLength, T tMaxLength);
	template <typename T>
	inline T VectorDot(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1);
	template <typename T>
	inline TRFVector4<T> VectorLerp(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1, T tT);
	template <typename T>
	inline TRFVector4<T> VectorSmoothStep(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1, T tT);
	template <typename T>
	inline T VectorLength(const TRFVector4<T>& kVec);
	template <typename T>
	inline T VectorLengthSquared(const TRFVector4<T>& kVec);
	template <typename T>
	inline TRFVector4<T> VectorReciprocal(const TRFVector4<T>& kVec);
	template <typename T>
	inline T VectorReciprocalLength(const TRFVector4<T>& kVec);
	template <typename T>
	inline TRFVector4<T> VectorNormalize(const TRFVector4<T>& kVec);	
	template <typename T>
	inline TRFVector4<T> VectorReflect(const TRFVector4<T>& kIncident, const TRFVector4<T>& kNormal);
	template <typename T>
	inline TRFVector4<T> VectorRefract(const TRFVector4<T>& kIncident, const TRFVector4<T>& kNormal, T tRefractIndex);

	// Utility.
	template <typename T>
	void VectorComputeExtremesV(uint uiCount, const TRFVector4<T>* pkVectors, TRFVector4<T>& kMin, TRFVector4<T>& kMax);
	template <typename T>
	uint VectorIndexOfMaxAbsComponent(const TRFVector4<T>& kVec);
	template <typename T>
	inline TRFVector4<T> VectorFloor(const TRFVector4<T>& kVec);
	template <typename T>
	inline TRFVector4<T> VectorAbs(const TRFVector4<T>& kVec);
	template <typename T>
	inline TRFVector4<T> VectorMin(const TRFVector4<T>& kVec);
	template <typename T>
	inline TRFVector4<T> VectorMax(const TRFVector4<T>& kVec);

	// Size types.
	typedef TRFVector4<float> RFVector4f;
	typedef TRFVector4<double> RFVector4d;
	typedef TRFVector4<int8> RFVector4i8;
	typedef TRFVector4<uint8> RFVector4ui8;
	typedef TRFVector4<int16> RFVector4i16;
	typedef TRFVector4<uint16> RFVector4ui16;
	typedef TRFVector4<int32> RFVector4i;
	typedef TRFVector4<uint32> RFVector4ui;
	typedef TRFVector4<int64> RFVector4i64;
	typedef TRFVector4<uint64> RFVector4ui64;
}

#include "TRFVector4.inl"
