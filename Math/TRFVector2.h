#pragma once

namespace RFMath
{
	template <typename T>
	struct TRFVector2
	{
		// Typedefs.
		typedef TRFVector2<T> type;
		typedef T value_type;

		// Data.
		union
		{
			struct { T x, y; };
			struct { T tX, tY; };
		};

		// Constructors.
		inline TRFVector2();
		inline TRFVector2(const TRFVector2<T>& kVec);
		explicit inline TRFVector2(T tValue); 
		inline TRFVector2(T tX, T tY);
		explicit inline TRFVector2(T tData[2]);

		// Conversion constructors.
		template <typename U>
		explicit inline TRFVector2(const TRFVector2<U>& kVec);

		// Access operators.
		inline T& operator[](int i);
		inline T operator[](int i) const;

		// Data pointer access.
		inline T* Data();
		inline const T* Data() const;

		// Unary arithmetic operators.
		inline TRFVector2<T>& operator=(const TRFVector2<T>& kVec);
	
		inline TRFVector2<T>& operator+=(T tValue);
		inline TRFVector2<T>& operator+=(const TRFVector2<T>& kVec);
		
		inline TRFVector2<T>& operator-=(T tValue);
		inline TRFVector2<T>& operator-=(const TRFVector2<T>& kVec);
		
		inline TRFVector2<T>& operator*=(T tValue);
		inline TRFVector2<T>& operator*=(const TRFVector2<T>& kVec);
		
		inline TRFVector2<T>& operator/=(T tValue);
		inline TRFVector2<T>& operator/=(const TRFVector2<T>& kVec);
	};

	// Binary arithmetic operators.
	template <typename T>
	inline TRFVector2<T> operator+(const TRFVector2<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector2<T> operator+(T tValue, const TRFVector2<T>& kVec);
	template <typename T> 
	inline TRFVector2<T> operator+(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);

	template <typename T>
	inline TRFVector2<T> operator-(const TRFVector2<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector2<T> operator-(T tValue, const TRFVector2<T>& kVec);
	template <typename T> 
	inline TRFVector2<T> operator-(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);

	template <typename T>
	inline TRFVector2<T> operator*(const TRFVector2<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector2<T> operator*(T tValue, const TRFVector2<T>& kVec);
	template <typename T> 
	inline TRFVector2<T> operator*(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);

	template <typename T>
	inline TRFVector2<T> operator/(const TRFVector2<T>& kVec, T tValue);
	template <typename T>
	inline TRFVector2<T> operator/(T tValue, const TRFVector2<T>& kVec);
	template <typename T> 
	inline TRFVector2<T> operator/(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);

	// Unary constant operators.
	template <typename T> 
	inline TRFVector2<T> operator-(const TRFVector2<T>& kVec);

	// Binary operators.
	template <typename T> 
	inline bool operator==(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);
	template <typename T>
	inline bool operator!=(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);	

	// Streaming.
 	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFVector2<T>& kVec);

	// Geometric functions.
	template <typename T>
	inline T VectorAngleBetweenNormals(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);
	template <typename T>
	inline T VectorAngleBetweenVectors(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);
	template <typename T>
	inline TRFVector2<T> VectorClamp(const TRFVector2<T>& kVec, T tMin, T tMax);
	template <typename T>
	inline TRFVector2<T> VectorClampLength(const TRFVector2<T>& kVec, T tMinLength, T tMaxLength);
	template <typename T>
	inline TRFVector2<T> VectorCross(const TRFVector2<T>& kVec);
	template <typename T>
	inline T VectorDot(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1);
	template <typename T>
	inline TRFVector2<T> VectorLerp(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1, T tT);
	template <typename T>
	inline TRFVector2<T> VectorSmoothStep(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1, T tT);
	template <typename T>
	inline T VectorLength(const TRFVector2<T>& kVec);
	template <typename T>
	inline T VectorLengthSquared(const TRFVector2<T>& kVec);
	template <typename T>
	inline TRFVector2<T> VectorReciprocal(const TRFVector2<T>& kVec);
	template <typename T>
	inline T VectorReciprocalLength(const TRFVector2<T>& kVec);
	template <typename T>
	inline TRFVector2<T> VectorNormalize(const TRFVector2<T>& kVec);	
	template <typename T>
	inline TRFVector2<T> VectorReflect(const TRFVector2<T>& kIncident, const TRFVector2<T>& kNormal);
	template <typename T>
	inline TRFVector2<T> VectorRefract(const TRFVector2<T>& kIncident, const TRFVector2<T>& kNormal, T tRefractIndex);

	// Utility.
	template <typename T>
	void VectorComputeExtremesV(uint uiCount, const TRFVector2<T>* pkVectors, TRFVector2<T>& kMin, TRFVector2<T>& kMax);
	template <typename T>
	uint VectorIndexOfMaxAbsComponent(const TRFVector2<T>& kVec);
	template <typename T>
	inline TRFVector2<T> VectorFloor(const TRFVector2<T>& kVec);
	template <typename T>
	inline TRFVector2<T> VectorAbs(const TRFVector2<T>& kVec);
	template <typename T>
	inline TRFVector2<T> VectorMin(const TRFVector2<T>& kVec);
	template <typename T>
	inline TRFVector2<T> VectorMax(const TRFVector2<T>& kVec);


	// Size types.
	typedef TRFVector2<float> RFVector2f;
	typedef TRFVector2<double> RFVector2d;
	typedef TRFVector2<int8> RFVector2i8;
	typedef TRFVector2<uint8> RFVector2ui8;
	typedef TRFVector2<int16> RFVector2i16;
	typedef TRFVector2<uint16> RFVector2ui16;
	typedef TRFVector2<int32> RFVector2i;
	typedef TRFVector2<uint32> RFVector2ui;
	typedef TRFVector2<int64> RFVector2i64;
	typedef TRFVector2<uint64> RFVector2ui64;
}

#include "TRFVector2.inl"
