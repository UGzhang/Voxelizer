#pragma once

#include "TRFVector3.h"

namespace RFMath
{
	template <typename T>
	struct TRFAABB3
	{
		// Typedefs.
		typedef TRFAABB3<T> type;
		typedef T value_type;

		// Data.
		TRFVector3<T> kMin;
		TRFVector3<T> kMax;

		// Constructors.
		inline TRFAABB3();
		inline TRFAABB3(const TRFAABB3<T>& kAABB);
		inline TRFAABB3(const T& tMinX, const T& tMinY, const T& tMinZ, const T& tMaxX, const T& tMaxY, const T& tMaxZ);
		inline TRFAABB3(const TRFVector3<T>& kMin, const TRFVector3<T>& kMax);

		// Conversion constructors.
		template <typename U>
		explicit inline TRFAABB3(const TRFAABB3<U>& kAABB);		

		// Unary arithmetic operators.
		inline TRFAABB3<T>& operator =(const TRFAABB3<T>& kAABB);

		// Extends.
		
		inline T GetWidth() const; //difference of x
		inline T GetHeight() const;//difference of y
		inline T GetDepth() const; //difference of z
		inline TRFVector3<T> GetCenter() const;
		inline void GetCenterExtends(TRFVector3<T>& kCenter, T& tExtendsX, T& tExtendsY, T& tExtendsZ) const;
		inline TRFVector3<T> GetDimensions() const;
		inline T GetMaxDimension() const;
	};

	// Binary operators.
	template <typename T> 
	inline bool operator==(const TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1);
	template <typename T>
	inline bool operator!=(const TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1);

	//2022.2.10 Aaron
	// Add + operator
	//


	// Streaming.
	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFAABB3<T>& kAABB);

	// Merging.
	template <typename T>
	inline TRFAABB3<T> AABBMerge(const TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1);
	template <typename T>
	inline TRFAABB3<T> AABBMerge(const TRFAABB3<T>& kAABB0, const TRFVector3<T>& kPoint);
	template <typename T>
	inline void AABBMergeInPlace(TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1);
	template <typename T>
	inline void AABBMergeInPlace(TRFAABB3<T>& kAABB, const TRFVector3<T>& kPoint);

	// Size types.
	typedef TRFAABB3<float> RFAABB3f;
	typedef TRFAABB3<double> RFAABB3d;
	typedef TRFAABB3<int8> RFAABB3i8;
	typedef TRFAABB3<uint8> RFAABB3ui8;
	typedef TRFAABB3<int16> RFAABB3i16;
	typedef TRFAABB3<uint16> RFAABB3ui16;
	typedef TRFAABB3<int32> RFAABB3i;
	typedef TRFAABB3<uint32> RFAABB3ui;
	typedef TRFAABB3<int64> RFAABB3i64;
	typedef TRFAABB3<uint64> RFAABB3ui64;
}

#include "TRFAABB3.inl"