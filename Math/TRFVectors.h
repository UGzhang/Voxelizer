#pragma once

#include <stdint.h>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;
typedef uint32_t uint;
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;


// Forward declarations.
namespace RFMath
{	
	template <typename T>
	struct TRFVector2;
	template <typename T>
	struct TRFVector3;
	template <typename T>
	struct TRFVector4;
}

namespace RFMath
{    
	template <typename T>
	struct TRFVectors2
	{
		// Static values.
		static TRFVector2<T> ZERO;
		static TRFVector2<T> ONE;
		static TRFVector2<T> UNIT_X;
		static TRFVector2<T> UNIT_Y;
		static TRFVector2<T> MIN;
		static TRFVector2<T> MAX;
	};

	template <typename T>
	struct TRFVectors3
	{
		// Static values.
		static TRFVector3<T> ZERO;
		static TRFVector3<T> ONE;
		static TRFVector3<T> UNIT_X;
		static TRFVector3<T> UNIT_Y;
		static TRFVector3<T> UNIT_Z;
		static TRFVector3<T> MIN;
		static TRFVector3<T> MAX;
	};

	template <typename T>
	struct TRFVectors4
	{
		// Static values.
		static TRFVector4<T> ZERO;
		static TRFVector4<T> ONE;
		static TRFVector4<T> UNIT_X;
		static TRFVector4<T> UNIT_Y;
		static TRFVector4<T> UNIT_Z;
		static TRFVector4<T> UNIT_W;
		static TRFVector4<T> MIN;
		static TRFVector4<T> MAX;
	};

	// Type defines.
	typedef TRFVectors2<float> RFVectors2f;
	typedef TRFVectors2<double> RFVectors2d;
	typedef TRFVectors2<int8> RFVectors2i8;
	typedef TRFVectors2<uint8> RFVectors2ui8;
	typedef TRFVectors2<int16> RFVectors2i16;
	typedef TRFVectors2<uint16> RFVectors2ui16;
	typedef TRFVectors2<int32> RFVectors2i;
	typedef TRFVectors2<uint32> RFVectors2ui;
	typedef TRFVectors2<int64> RFVectors2i64;
	typedef TRFVectors2<uint64> RFVectors2ui64;

	typedef TRFVectors3<float> RFVectors3f;
	typedef TRFVectors3<double> RFVectors3d;
	typedef TRFVectors3<int8> RFVectors3i8;
	typedef TRFVectors3<uint8> RFVectors3ui8;
	typedef TRFVectors3<int16> RFVectors3i16;
	typedef TRFVectors3<uint16> RFVectors3ui16;
	typedef TRFVectors3<int32> RFVectors3i;
	typedef TRFVectors3<uint32> RFVectors3ui;
	typedef TRFVectors3<int64> RFVectors3i64;
	typedef TRFVectors3<uint64> RFVectors3ui64;

	typedef TRFVectors4<float> RFVectors4f;
	typedef TRFVectors4<double> RFVectors4d;
	typedef TRFVectors4<int8> RFVectors4i8;
	typedef TRFVectors4<uint8> RFVectors4ui8;
	typedef TRFVectors4<int16> RFVectors4i16;
	typedef TRFVectors4<uint16> RFVectors4ui16;
	typedef TRFVectors4<int32> RFVectors4i;
	typedef TRFVectors4<uint32> RFVectors4ui;
	typedef TRFVectors4<int64> RFVectors4i64;
	typedef TRFVectors4<uint64> RFVectors4ui64;
}