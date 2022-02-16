
#include <fstream>
#include "TRFVectors.h"
#include "TRFVector2.h"
#include "TRFVector3.h"
#include "TRFVector4.h"

using namespace RFMath;

//-------------------------------------------------------------------------

template<> RFVector2f RFVectors2f::ZERO			= RFVector2f(0.0f, 0.0f);
template<> RFVector2f RFVectors2f::ONE			= RFVector2f(1.0f, 1.0f);
template<> RFVector2f RFVectors2f::UNIT_X		= RFVector2f(1.0f, 0.0f);
template<> RFVector2f RFVectors2f::UNIT_Y		= RFVector2f(0.0f, 1.0f);
template<> RFVector2f RFVectors2f::MIN			= RFVector2f(-std::numeric_limits<float>::max());
template<> RFVector2f RFVectors2f::MAX			= RFVector2f(std::numeric_limits<float>::max());

template<> RFVector2d RFVectors2d::ZERO			= RFVector2d(0.0, 0.0);
template<> RFVector2d RFVectors2d::ONE			= RFVector2d(1.0, 1.0);
template<> RFVector2d RFVectors2d::UNIT_X		= RFVector2d(1.0, 0.0);
template<> RFVector2d RFVectors2d::UNIT_Y		= RFVector2d(0.0, 1.0);
template<> RFVector2d RFVectors2d::MIN			= RFVector2d(-std::numeric_limits<double>::max());
template<> RFVector2d RFVectors2d::MAX			= RFVector2d(std::numeric_limits<double>::max());

template<> RFVector2i8 RFVectors2i8::ZERO		= RFVector2i8(0, 0);
template<> RFVector2i8 RFVectors2i8::ONE		= RFVector2i8(1, 1);
template<> RFVector2i8 RFVectors2i8::UNIT_X		= RFVector2i8(1, 0);
template<> RFVector2i8 RFVectors2i8::UNIT_Y		= RFVector2i8(0, 1);
template<> RFVector2i8 RFVectors2i8::MIN		= RFVector2i8(std::numeric_limits<int8>::min());
template<> RFVector2i8 RFVectors2i8::MAX		= RFVector2i8(std::numeric_limits<int8>::max());

template<> RFVector2ui8 RFVectors2ui8::ZERO		= RFVector2ui8(0u, 0u);
template<> RFVector2ui8 RFVectors2ui8::ONE		= RFVector2ui8(1u, 1u);
template<> RFVector2ui8 RFVectors2ui8::UNIT_X	= RFVector2ui8(1u, 0u);
template<> RFVector2ui8 RFVectors2ui8::UNIT_Y	= RFVector2ui8(0u, 1u);
template<> RFVector2ui8 RFVectors2ui8::MIN		= RFVector2ui8(std::numeric_limits<uint8>::min());
template<> RFVector2ui8 RFVectors2ui8::MAX		= RFVector2ui8(std::numeric_limits<uint8>::max());

template<> RFVector2i16 RFVectors2i16::ZERO		= RFVector2i16(0, 0);
template<> RFVector2i16 RFVectors2i16::ONE		= RFVector2i16(1, 1);
template<> RFVector2i16 RFVectors2i16::UNIT_X	= RFVector2i16(1, 0);
template<> RFVector2i16 RFVectors2i16::UNIT_Y	= RFVector2i16(0, 1);
template<> RFVector2i16 RFVectors2i16::MIN		= RFVector2i16(std::numeric_limits<int16>::min());
template<> RFVector2i16 RFVectors2i16::MAX		= RFVector2i16(std::numeric_limits<int16>::max());

template<> RFVector2ui16 RFVectors2ui16::ZERO	= RFVector2ui16(0u, 0u);
template<> RFVector2ui16 RFVectors2ui16::ONE	= RFVector2ui16(1u, 1u);
template<> RFVector2ui16 RFVectors2ui16::UNIT_X	= RFVector2ui16(1u, 0u);
template<> RFVector2ui16 RFVectors2ui16::UNIT_Y	= RFVector2ui16(0u, 1u);
template<> RFVector2ui16 RFVectors2ui16::MIN	= RFVector2ui16(std::numeric_limits<uint16>::min());
template<> RFVector2ui16 RFVectors2ui16::MAX	= RFVector2ui16(std::numeric_limits<uint16>::max());

template<> RFVector2i RFVectors2i::ZERO			= RFVector2i(0, 0);
template<> RFVector2i RFVectors2i::ONE			= RFVector2i(1, 1);
template<> RFVector2i RFVectors2i::UNIT_X		= RFVector2i(1, 0);
template<> RFVector2i RFVectors2i::UNIT_Y		= RFVector2i(0, 1);
template<> RFVector2i RFVectors2i::MIN			= RFVector2i(-std::numeric_limits<int32>::max());
template<> RFVector2i RFVectors2i::MAX			= RFVector2i(std::numeric_limits<int32>::max());

template<> RFVector2ui RFVectors2ui::ZERO		= RFVector2ui(0u, 0u);
template<> RFVector2ui RFVectors2ui::ONE		= RFVector2ui(1u, 1u);
template<> RFVector2ui RFVectors2ui::UNIT_X		= RFVector2ui(1u, 0u);
template<> RFVector2ui RFVectors2ui::UNIT_Y		= RFVector2ui(0u, 1u);
template<> RFVector2ui RFVectors2ui::MIN		= RFVector2ui(std::numeric_limits<uint32>::min());
template<> RFVector2ui RFVectors2ui::MAX		= RFVector2ui(std::numeric_limits<uint32>::max());

template<> RFVector2i64 RFVectors2i64::ZERO		= RFVector2i64(0ll, 0ll);
template<> RFVector2i64 RFVectors2i64::ONE		= RFVector2i64(1ll, 1ll);
template<> RFVector2i64 RFVectors2i64::UNIT_X	= RFVector2i64(1ll, 0ll);
template<> RFVector2i64 RFVectors2i64::UNIT_Y	= RFVector2i64(0ll, 1ll);
template<> RFVector2i64 RFVectors2i64::MIN		= RFVector2i64(std::numeric_limits<int64>::min());
template<> RFVector2i64 RFVectors2i64::MAX		= RFVector2i64(std::numeric_limits<int64>::max());

template<> RFVector2ui64 RFVectors2ui64::ZERO	= RFVector2ui64(0ull, 0ull);
template<> RFVector2ui64 RFVectors2ui64::ONE	= RFVector2ui64(1ull, 1ull);
template<> RFVector2ui64 RFVectors2ui64::UNIT_X	= RFVector2ui64(1ull, 0ull);
template<> RFVector2ui64 RFVectors2ui64::UNIT_Y	= RFVector2ui64(0ull, 1ull);
template<> RFVector2ui64 RFVectors2ui64::MIN	= RFVector2ui64(std::numeric_limits<uint64>::min());
template<> RFVector2ui64 RFVectors2ui64::MAX	= RFVector2ui64(std::numeric_limits<uint64>::max());

//-------------------------------------------------------------------------

template<> RFVector3f RFVectors3f::ZERO			= RFVector3f(0.0f, 0.0f, 0.0f);
template<> RFVector3f RFVectors3f::ONE			= RFVector3f(1.0f, 1.0f, 1.0f);
template<> RFVector3f RFVectors3f::UNIT_X		= RFVector3f(1.0f, 0.0f, 0.0f);
template<> RFVector3f RFVectors3f::UNIT_Y		= RFVector3f(0.0f, 1.0f, 0.0f);
template<> RFVector3f RFVectors3f::UNIT_Z		= RFVector3f(0.0f, 0.0f, 1.0f);
template<> RFVector3f RFVectors3f::MIN			= RFVector3f(-std::numeric_limits<float>::max());
template<> RFVector3f RFVectors3f::MAX			= RFVector3f(std::numeric_limits<float>::max());

template<> RFVector3d RFVectors3d::ZERO			= RFVector3d(0.0, 0.0, 0.0);
template<> RFVector3d RFVectors3d::ONE			= RFVector3d(1.0, 1.0, 1.0);
template<> RFVector3d RFVectors3d::UNIT_X		= RFVector3d(1.0, 0.0, 0.0);
template<> RFVector3d RFVectors3d::UNIT_Y		= RFVector3d(0.0, 1.0, 0.0);
template<> RFVector3d RFVectors3d::UNIT_Z		= RFVector3d(0.0, 0.0, 1.0);
template<> RFVector3d RFVectors3d::MIN			= RFVector3d(-std::numeric_limits<double>::max());
template<> RFVector3d RFVectors3d::MAX			= RFVector3d(std::numeric_limits<double>::max());

template<> RFVector3i8 RFVectors3i8::ZERO		= RFVector3i8(0, 0, 0);
template<> RFVector3i8 RFVectors3i8::ONE		= RFVector3i8(1, 1, 1);
template<> RFVector3i8 RFVectors3i8::UNIT_X		= RFVector3i8(1, 0, 0);
template<> RFVector3i8 RFVectors3i8::UNIT_Y		= RFVector3i8(0, 1, 0);
template<> RFVector3i8 RFVectors3i8::UNIT_Z		= RFVector3i8(0, 0, 1);
template<> RFVector3i8 RFVectors3i8::MIN		= RFVector3i8(std::numeric_limits<int8>::min());
template<> RFVector3i8 RFVectors3i8::MAX		= RFVector3i8(std::numeric_limits<int8>::max());

template<> RFVector3ui8 RFVectors3ui8::ZERO		= RFVector3ui8(0u, 0u, 0u);
template<> RFVector3ui8 RFVectors3ui8::ONE		= RFVector3ui8(1u, 1u, 1u);
template<> RFVector3ui8 RFVectors3ui8::UNIT_X	= RFVector3ui8(1u, 0u, 0u);
template<> RFVector3ui8 RFVectors3ui8::UNIT_Y	= RFVector3ui8(0u, 1u, 0u);
template<> RFVector3ui8 RFVectors3ui8::UNIT_Z	= RFVector3ui8(0u, 0u, 1u);
template<> RFVector3ui8 RFVectors3ui8::MIN		= RFVector3ui8(std::numeric_limits<uint8>::min());
template<> RFVector3ui8 RFVectors3ui8::MAX		= RFVector3ui8(std::numeric_limits<uint8>::max());

template<> RFVector3i16 RFVectors3i16::ZERO		= RFVector3i16(0, 0, 0);
template<> RFVector3i16 RFVectors3i16::ONE		= RFVector3i16(1, 1, 1);
template<> RFVector3i16 RFVectors3i16::UNIT_X	= RFVector3i16(1, 0, 0);
template<> RFVector3i16 RFVectors3i16::UNIT_Y	= RFVector3i16(0, 1, 0);
template<> RFVector3i16 RFVectors3i16::UNIT_Z	= RFVector3i16(0, 0, 1);
template<> RFVector3i16 RFVectors3i16::MIN		= RFVector3i16(std::numeric_limits<int16>::min());
template<> RFVector3i16 RFVectors3i16::MAX		= RFVector3i16(std::numeric_limits<int16>::max());

template<> RFVector3ui16 RFVectors3ui16::ZERO	= RFVector3ui16(0u, 0u, 0u);
template<> RFVector3ui16 RFVectors3ui16::ONE	= RFVector3ui16(1u, 1u, 1u);
template<> RFVector3ui16 RFVectors3ui16::UNIT_X	= RFVector3ui16(1u, 0u, 0u);
template<> RFVector3ui16 RFVectors3ui16::UNIT_Y	= RFVector3ui16(0u, 1u, 0u);
template<> RFVector3ui16 RFVectors3ui16::UNIT_Z	= RFVector3ui16(0u, 0u, 1u);
template<> RFVector3ui16 RFVectors3ui16::MIN	= RFVector3ui16(std::numeric_limits<uint16>::min());
template<> RFVector3ui16 RFVectors3ui16::MAX	= RFVector3ui16(std::numeric_limits<uint16>::max());

template<> RFVector3i RFVectors3i::ZERO			= RFVector3i(0, 0, 0);
template<> RFVector3i RFVectors3i::ONE			= RFVector3i(1, 1, 1);
template<> RFVector3i RFVectors3i::UNIT_X		= RFVector3i(1, 0, 0);
template<> RFVector3i RFVectors3i::UNIT_Y		= RFVector3i(0, 1, 0);
template<> RFVector3i RFVectors3i::UNIT_Z		= RFVector3i(0, 0, 1);
template<> RFVector3i RFVectors3i::MIN			= RFVector3i(-std::numeric_limits<int32>::max());
template<> RFVector3i RFVectors3i::MAX			= RFVector3i(std::numeric_limits<int32>::max());

template<> RFVector3ui RFVectors3ui::ZERO		= RFVector3ui(0u, 0u, 0u);
template<> RFVector3ui RFVectors3ui::ONE		= RFVector3ui(1u, 1u, 1u);
template<> RFVector3ui RFVectors3ui::UNIT_X		= RFVector3ui(1u, 0u, 0u);
template<> RFVector3ui RFVectors3ui::UNIT_Y		= RFVector3ui(0u, 1u, 0u);
template<> RFVector3ui RFVectors3ui::UNIT_Z		= RFVector3ui(0u, 0u, 1u);
template<> RFVector3ui RFVectors3ui::MIN		= RFVector3ui(std::numeric_limits<uint32>::min());
template<> RFVector3ui RFVectors3ui::MAX		= RFVector3ui(std::numeric_limits<uint32>::max());

template<> RFVector3i64 RFVectors3i64::ZERO		= RFVector3i64(0ll, 0ll, 0ll);
template<> RFVector3i64 RFVectors3i64::ONE		= RFVector3i64(1ll, 1ll, 1ll);
template<> RFVector3i64 RFVectors3i64::UNIT_X	= RFVector3i64(1ll, 0ll, 0ll);
template<> RFVector3i64 RFVectors3i64::UNIT_Y	= RFVector3i64(0ll, 1ll, 0ll);
template<> RFVector3i64 RFVectors3i64::UNIT_Z	= RFVector3i64(0ll, 0ll, 1ll);
template<> RFVector3i64 RFVectors3i64::MIN		= RFVector3i64(std::numeric_limits<int64>::min());
template<> RFVector3i64 RFVectors3i64::MAX		= RFVector3i64(std::numeric_limits<int64>::max());

template<> RFVector3ui64 RFVectors3ui64::ZERO	= RFVector3ui64(0ull, 0ull, 0ull);
template<> RFVector3ui64 RFVectors3ui64::ONE	= RFVector3ui64(1ull, 1ull, 1ull);
template<> RFVector3ui64 RFVectors3ui64::UNIT_X	= RFVector3ui64(1ull, 0ull, 0ull);
template<> RFVector3ui64 RFVectors3ui64::UNIT_Y	= RFVector3ui64(0ull, 1ull, 0ull);
template<> RFVector3ui64 RFVectors3ui64::UNIT_Z	= RFVector3ui64(0ull, 0ull, 1ull);
template<> RFVector3ui64 RFVectors3ui64::MIN	= RFVector3ui64(std::numeric_limits<uint64>::min());
template<> RFVector3ui64 RFVectors3ui64::MAX	= RFVector3ui64(std::numeric_limits<uint64>::max());

//-------------------------------------------------------------------------

template<> RFVector4f RFVectors4f::ZERO			= RFVector4f(0.0f, 0.0f, 0.0f, 0.0f);
template<> RFVector4f RFVectors4f::ONE			= RFVector4f(1.0f, 1.0f, 1.0f, 1.0f);
template<> RFVector4f RFVectors4f::UNIT_X		= RFVector4f(1.0f, 0.0f, 0.0f, 0.0f);
template<> RFVector4f RFVectors4f::UNIT_Y		= RFVector4f(0.0f, 1.0f, 0.0f, 0.0f);
template<> RFVector4f RFVectors4f::UNIT_Z		= RFVector4f(0.0f, 0.0f, 1.0f, 0.0f);
template<> RFVector4f RFVectors4f::UNIT_W		= RFVector4f(0.0f, 0.0f, 0.0f, 1.0f);
template<> RFVector4f RFVectors4f::MIN			= RFVector4f(-std::numeric_limits<float>::max());
template<> RFVector4f RFVectors4f::MAX			= RFVector4f(std::numeric_limits<float>::max());

template<> RFVector4d RFVectors4d::ZERO			= RFVector4d(0.0, 0.0, 0.0, 0.0);
template<> RFVector4d RFVectors4d::ONE			= RFVector4d(1.0, 1.0, 1.0, 1.0);
template<> RFVector4d RFVectors4d::UNIT_X		= RFVector4d(1.0, 0.0, 0.0, 0.0);
template<> RFVector4d RFVectors4d::UNIT_Y		= RFVector4d(0.0, 1.0, 0.0, 0.0);
template<> RFVector4d RFVectors4d::UNIT_Z		= RFVector4d(0.0, 0.0, 1.0, 0.0);
template<> RFVector4d RFVectors4d::UNIT_W		= RFVector4d(0.0, 0.0, 0.0, 1.0);
template<> RFVector4d RFVectors4d::MIN			= RFVector4d(-std::numeric_limits<double>::max());
template<> RFVector4d RFVectors4d::MAX			= RFVector4d(std::numeric_limits<double>::max());

template<> RFVector4i8 RFVectors4i8::ZERO		= RFVector4i8(0, 0, 0, 0);
template<> RFVector4i8 RFVectors4i8::ONE		= RFVector4i8(1, 1, 1, 1);
template<> RFVector4i8 RFVectors4i8::UNIT_X		= RFVector4i8(1, 0, 0, 0);
template<> RFVector4i8 RFVectors4i8::UNIT_Y		= RFVector4i8(0, 1, 0, 0);
template<> RFVector4i8 RFVectors4i8::UNIT_Z		= RFVector4i8(0, 0, 1, 0);
template<> RFVector4i8 RFVectors4i8::UNIT_W		= RFVector4i8(0, 0, 0, 1);
template<> RFVector4i8 RFVectors4i8::MIN		= RFVector4i8(std::numeric_limits<int8>::min());
template<> RFVector4i8 RFVectors4i8::MAX		= RFVector4i8(std::numeric_limits<int8>::max());

template<> RFVector4ui8 RFVectors4ui8::ZERO		= RFVector4ui8(0u, 0u, 0u, 0u);
template<> RFVector4ui8 RFVectors4ui8::ONE		= RFVector4ui8(1u, 1u, 1u, 1u);
template<> RFVector4ui8 RFVectors4ui8::UNIT_X	= RFVector4ui8(1u, 0u, 0u, 0u);
template<> RFVector4ui8 RFVectors4ui8::UNIT_Y	= RFVector4ui8(0u, 1u, 0u, 0u);
template<> RFVector4ui8 RFVectors4ui8::UNIT_Z	= RFVector4ui8(0u, 0u, 1u, 0u);
template<> RFVector4ui8 RFVectors4ui8::UNIT_W	= RFVector4ui8(0u, 0u, 0u, 1u);
template<> RFVector4ui8 RFVectors4ui8::MIN		= RFVector4ui8(std::numeric_limits<uint8>::min());
template<> RFVector4ui8 RFVectors4ui8::MAX		= RFVector4ui8(std::numeric_limits<uint8>::max());

template<> RFVector4i16 RFVectors4i16::ZERO		= RFVector4i16(0, 0, 0, 0);
template<> RFVector4i16 RFVectors4i16::ONE		= RFVector4i16(1, 1, 1, 1);
template<> RFVector4i16 RFVectors4i16::UNIT_X	= RFVector4i16(1, 0, 0, 0);
template<> RFVector4i16 RFVectors4i16::UNIT_Y	= RFVector4i16(0, 1, 0, 0);
template<> RFVector4i16 RFVectors4i16::UNIT_Z	= RFVector4i16(0, 0, 1, 0);
template<> RFVector4i16 RFVectors4i16::UNIT_W	= RFVector4i16(0, 0, 0, 1);
template<> RFVector4i16 RFVectors4i16::MIN		= RFVector4i16(std::numeric_limits<int16>::min());
template<> RFVector4i16 RFVectors4i16::MAX		= RFVector4i16(std::numeric_limits<int16>::max());

template<> RFVector4ui16 RFVectors4ui16::ZERO	= RFVector4ui16(0u, 0u, 0u, 0u);
template<> RFVector4ui16 RFVectors4ui16::ONE	= RFVector4ui16(1u, 1u, 1u, 1u);
template<> RFVector4ui16 RFVectors4ui16::UNIT_X	= RFVector4ui16(1u, 0u, 0u, 0u);
template<> RFVector4ui16 RFVectors4ui16::UNIT_Y	= RFVector4ui16(0u, 1u, 0u, 0u);
template<> RFVector4ui16 RFVectors4ui16::UNIT_Z	= RFVector4ui16(0u, 0u, 1u, 0u);
template<> RFVector4ui16 RFVectors4ui16::UNIT_W	= RFVector4ui16(0u, 0u, 0u, 1u);
template<> RFVector4ui16 RFVectors4ui16::MIN	= RFVector4ui16(std::numeric_limits<uint16>::min());
template<> RFVector4ui16 RFVectors4ui16::MAX	= RFVector4ui16(std::numeric_limits<uint16>::max());

template<> RFVector4i RFVectors4i::ZERO			= RFVector4i(0, 0, 0, 0);
template<> RFVector4i RFVectors4i::ONE			= RFVector4i(1, 1, 1, 1);
template<> RFVector4i RFVectors4i::UNIT_X		= RFVector4i(1, 0, 0, 0);
template<> RFVector4i RFVectors4i::UNIT_Y		= RFVector4i(0, 1, 0, 0);
template<> RFVector4i RFVectors4i::UNIT_Z		= RFVector4i(0, 0, 1, 0);
template<> RFVector4i RFVectors4i::UNIT_W		= RFVector4i(0, 0, 0, 1);
template<> RFVector4i RFVectors4i::MIN			= RFVector4i(-std::numeric_limits<int32>::max());
template<> RFVector4i RFVectors4i::MAX			= RFVector4i(std::numeric_limits<int32>::max());

template<> RFVector4ui RFVectors4ui::ZERO		= RFVector4ui(0u, 0u, 0u, 0u);
template<> RFVector4ui RFVectors4ui::ONE		= RFVector4ui(1u, 1u, 1u, 1u);
template<> RFVector4ui RFVectors4ui::UNIT_X		= RFVector4ui(1u, 0u, 0u, 0u);
template<> RFVector4ui RFVectors4ui::UNIT_Y		= RFVector4ui(0u, 1u, 0u, 0u);
template<> RFVector4ui RFVectors4ui::UNIT_Z		= RFVector4ui(0u, 0u, 1u, 0u);
template<> RFVector4ui RFVectors4ui::UNIT_W		= RFVector4ui(0u, 0u, 0u, 1u);
template<> RFVector4ui RFVectors4ui::MIN		= RFVector4ui(std::numeric_limits<uint32>::min());
template<> RFVector4ui RFVectors4ui::MAX		= RFVector4ui(std::numeric_limits<uint32>::max());

template<> RFVector4i64 RFVectors4i64::ZERO		= RFVector4i64(0, 0, 0, 0);
template<> RFVector4i64 RFVectors4i64::ONE		= RFVector4i64(1, 1, 1, 1);
template<> RFVector4i64 RFVectors4i64::UNIT_X	= RFVector4i64(1, 0, 0, 0);
template<> RFVector4i64 RFVectors4i64::UNIT_Y	= RFVector4i64(0, 1, 0, 0);
template<> RFVector4i64 RFVectors4i64::UNIT_Z	= RFVector4i64(0, 0, 1, 0);
template<> RFVector4i64 RFVectors4i64::UNIT_W	= RFVector4i64(0, 0, 0, 1);
template<> RFVector4i64 RFVectors4i64::MIN		= RFVector4i64(std::numeric_limits<int64>::min());
template<> RFVector4i64 RFVectors4i64::MAX		= RFVector4i64(std::numeric_limits<int64>::max());

template<> RFVector4ui64 RFVectors4ui64::ZERO	= RFVector4ui64(0u, 0u, 0u, 0u);
template<> RFVector4ui64 RFVectors4ui64::ONE	= RFVector4ui64(1u, 1u, 1u, 1u);
template<> RFVector4ui64 RFVectors4ui64::UNIT_X	= RFVector4ui64(1u, 0u, 0u, 0u);
template<> RFVector4ui64 RFVectors4ui64::UNIT_Y	= RFVector4ui64(0u, 1u, 0u, 0u);
template<> RFVector4ui64 RFVectors4ui64::UNIT_Z	= RFVector4ui64(0u, 0u, 1u, 0u);
template<> RFVector4ui64 RFVectors4ui64::UNIT_W	= RFVector4ui64(0u, 0u, 0u, 1u);
template<> RFVector4ui64 RFVectors4ui64::MIN	= RFVector4ui64(std::numeric_limits<uint64>::min());
template<> RFVector4ui64 RFVectors4ui64::MAX	= RFVector4ui64(std::numeric_limits<uint64>::max());

//-------------------------------------------------------------------------