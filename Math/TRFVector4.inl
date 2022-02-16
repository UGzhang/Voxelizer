namespace RFMath
{
	//------------------------------------------------------------------------- 

	template <typename T>
	inline TRFVector4<T>::TRFVector4() :
		tX(T(0)),
		tY(T(0)),
		tZ(T(0)),
		tW(T(0))
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(const TRFVector4<T>& kVec) :
		tX(kVec.tX),
		tY(kVec.tY),
		tZ(kVec.tZ),
		tW(kVec.tW)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(T tValue) :
		tX(tValue),
		tY(tValue),
		tZ(tValue),
		tW(tValue)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(T tX, T tY, T tZ, T tW) :
		tX(tX),
		tY(tY),
		tZ(tZ),
		tW(tW)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(T tData[4]) :
		tX(tData[0]),
		tY(tData[1]),
		tZ(tData[2]),
		tW(tData[3])
	{
	}

	//-------------------------------------------------------------------------

	template <typename T>
	template <typename U>
	inline TRFVector4<T>::TRFVector4(const TRFVector4<U>& kVec) :
		tX(T(kVec.tX)),
		tY(T(kVec.tY)),
		tZ(T(kVec.tZ)),
		tW(T(kVec.tW))
	{
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T>::TRFVector4(const TRFVector2<T>& kVec, T tZ, T tW) :
		tX(kVec.tX),
		tY(kVec.tY),
		tZ(tZ),
		tW(tW)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(T tX, const TRFVector2<T>& kVec, T tW) :
		tX(tX),
		tY(kVec.tX),
		tZ(kVec.tY),
		tW(tW)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(T tX, T tY, const TRFVector2<T>& kVec) :
		tX(tX),
		tY(tY),
		tZ(kVec.tX),
		tW(kVec.tY)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1) :
		tX(kVec0.tX),
		tY(kVec0.tY),
		tZ(kVec1.tX),
		tW(kVec1.tY)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(const TRFVector3<T>& kVec, T tW) :
		tX(kVec.tX),
		tY(kVec.tY),
		tZ(kVec.tZ),
		tW(tW)
	{
	}

	template <typename T>
	inline TRFVector4<T>::TRFVector4(T tX, const TRFVector3<T>& kVec) :
		tX(tX),
		tY(kVec.tX),
		tZ(kVec.tY),
		tW(kVec.tZ)
	{
	}

	//------------------------------------------------------------------------- 

	template <typename T>
	inline T& TRFVector4<T>::operator[](int i)
	{
		RF_MATH_ASSERT(i >= 0 && i < 4);
		return Data()[i];
	}

	template <typename T>
	inline T TRFVector4<T>::operator[](int i) const
	{
		RF_MATH_ASSERT(i >= 0 && i < 4);
		return Data()[i];
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline T* TRFVector4<T>::Data()
	{
		return &tX;
	}

	template <typename T>
	inline const T* TRFVector4<T>::Data() const
	{
		return &tX;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T> TRFVector4<T>::AsVector2() const
	{
		return TRFVector2<T>(tX, tY);
	}
	
	template <typename T>
	inline TRFVector3<T> TRFVector4<T>::AsVector3() const
	{
		return TRFVector3<T>(tX, tY, tZ);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator=(const TRFVector4<T>& kVec)
	{
		tX = kVec.tX;
		tY = kVec.tY;
		tZ = kVec.tZ;
		tW = kVec.tW;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator+=(T tValue)
	{
		tX += tValue;
		tY += tValue;
		tZ += tValue;
		tW += tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator+=(const TRFVector4<T>& kVec)
	{
		tX += kVec.tX;
		tY += kVec.tY;
		tZ += kVec.tZ;
		tW += kVec.tW;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator-=(T tValue)
	{
		tX -= tValue;
		tY -= tValue;
		tZ -= tValue;
		tW -= tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator-=(const TRFVector4<T>& kVec)
	{
		tX -= kVec.tX;
		tY -= kVec.tY;
		tZ -= kVec.tZ;
		tW -= kVec.tW;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator*=(T tValue)
	{
		tX *= tValue;
		tY *= tValue;
		tZ *= tValue;
		tW *= tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator*=(const TRFVector4<T>& kVec)
	{
		tX *= kVec.tX;
		tY *= kVec.tY;
		tZ *= kVec.tZ;
		tW *= kVec.tW;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator/=(T tValue)
	{
		tX /= tValue;
		tY /= tValue;
		tZ /= tValue;
		tW /= tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector4<T>& TRFVector4<T>::operator/=(const TRFVector4<T>& kVec)
	{
		tX /= kVec.tX;
		tY /= kVec.tY;
		tZ /= kVec.tZ;
		tW /= kVec.tW;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T> operator+(const TRFVector4<T>& kVec, T tValue)
	{
		return TRFVector4<T>(kVec.tX + tValue, kVec.tY + tValue, kVec.tZ + tValue, kVec.tW + tValue);
	}

	template <typename T>
	inline TRFVector4<T> operator+(T tValue, const TRFVector4<T>& kVec)
	{
		return TRFVector4<T>(tValue + kVec.tX, tValue + kVec.tY, tValue + kVec.tZ, tValue + kVec.tW);
	}

	template <typename T> 
	inline TRFVector4<T> operator+(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return TRFVector4<T>(kVec0.tX + kVec1.tX, kVec0.tY + kVec1.tY, kVec0.tZ + kVec1.tZ, kVec0.tW + kVec1.tW);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T> operator-(const TRFVector4<T>& kVec, T tValue)
	{
		return TRFVector4<T>(kVec.tX - tValue, kVec.tY - tValue, kVec.tZ - tValue, kVec.tW - tValue);
	}

	template <typename T>
	inline TRFVector4<T> operator-(T tValue, const TRFVector4<T>& kVec)
	{
		return TRFVector4<T>(tValue - kVec.tX, tValue - kVec.tY, tValue - kVec.tZ, tValue - kVec.tW);
	}

	template <typename T> 
	inline TRFVector4<T> operator-(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return TRFVector4<T>(kVec0.tX - kVec1.tX, kVec0.tY - kVec1.tY, kVec0.tZ - kVec1.tZ, kVec0.tW - kVec1.tW);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T> operator*(const TRFVector4<T>& kVec, T tValue)
	{
		return TRFVector4<T>(kVec.tX * tValue, kVec.tY * tValue, kVec.tZ * tValue, kVec.tW * tValue);
	}

	template <typename T>
	inline TRFVector4<T> operator*(T tValue, const TRFVector4<T>& kVec)
	{
		return TRFVector4<T>(tValue * kVec.tX, tValue * kVec.tY, tValue * kVec.tZ, tValue * kVec.tW);
	}

	template <typename T> 
	inline TRFVector4<T> operator*(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return TRFVector4<T>(kVec0.tX * kVec1.tX, kVec0.tY * kVec1.tY, kVec0.tZ * kVec1.tZ, kVec0.tW * kVec1.tW);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector4<T> operator/(const TRFVector4<T>& kVec, T tValue)
	{
		return TRFVector4<T>(kVec.tX / tValue, kVec.tY / tValue, kVec.tZ / tValue, kVec.tW / tValue);
	}

	template <typename T>
	inline TRFVector4<T> operator/(T tValue, const TRFVector4<T>& kVec)
	{
		return TRFVector4<T>(tValue / kVec.tX, tValue / kVec.tY, tValue / kVec.tZ, tValue / kVec.tW);
	}

	template <typename T> 
	inline TRFVector4<T> operator/(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return TRFVector4<T>(kVec0.tX / kVec1.tX, kVec0.tY / kVec1.tY, kVec0.tZ / kVec1.tZ, kVec0.tW / kVec1.tW);
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline TRFVector4<T> operator-(const TRFVector4<T>& kVec)
	{
		static_assert(std::is_signed<T>::value, "operator- only works on signed types.");

		return TRFVector4<T>(-kVec.tX, -kVec.tY, -kVec.tZ, -kVec.tW);
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline bool operator==(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return (RFMemcmp(kVec0.Data(), kVec1.Data(), sizeof(TRFVector4<T>)) == 0);
	}

	template <typename T>
	inline bool operator!=(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return (RFMemcmp(kVec0.Data(), kVec1.Data(), sizeof(TRFVector4<T>)) != 0);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFVector4<T>& kVec)
	{
		kOs << "(" << kVec.tX << ", " << kVec.tY << ", " << kVec.tZ << ", " << kVec.tW << ")";
		return kOs;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline T VectorAngleBetweenNormals(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		static_assert(std::is_floating_point<T>::value, "VectorAngleBetweenNormals only works with floating point vectors.");

		return std::acos(VectorDot(kVec0, kVec1));
	}

	template <typename T>
	inline T VectorAngleBetweenVectors(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		static_assert(std::is_floating_point<T>::value, "VectorAngleBetweenVectors only works with floating point vectors.");

		return std::acos(VectorDot(kVec0, kVec1) / (VectorLength(kVec0) * VectorLength(kVec1)));
	}

	template <typename T>
	inline TRFVector4<T> VectorClamp(const TRFVector4<T>& kVec, T tMin, T tMax)
	{
		return TRFVector4<T>(
			RFClamp(kVec.tX, tMin, tMax),
			RFClamp(kVec.tY, tMin, tMax),
			RFClamp(kVec.tZ, tMin, tMax),
			RFClamp(kVec.tW, tMin, tMax));
	}

	template <typename T>
	inline TRFVector4<T> VectorClampLength(const TRFVector4<T>& kVec, T tMinLength, T tMaxLength)
	{
		static_assert(std::is_floating_point<T>::value, "VectorClampLength only works with floating point vectors.");

		RF_MATH_ASSERT(tMinLength > T(0));
		RF_MATH_ASSERT(tMaxLength > tMinLength);

		T tLenSqr = VectorLengthSquared(kVec);
		RF_MATH_ASSERT(T(0) != tLenSqr);
		if (tLenSqr < tMinLength * tMinLength)
			return kVec * (tMinLength / std::sqrt(tLenSqr));
		else if (tLenSqr > tMaxLength * tMaxLength)
			return kVec * (tMaxLength / std::sqrt(tLenSqr));
		else
			return kVec;
	}

	template <typename T>
	inline T VectorDot(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return (kVec0.tX * kVec1.tX) + (kVec0.tY * kVec1.tY) + (kVec0.tZ * kVec1.tZ) + (kVec0.tW * kVec1.tW);
	}

	template <typename T>
	inline TRFVector4<T> VectorLerp(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1, T tT)
	{
		static_assert(std::is_floating_point<T>::value, "VectorLerp only works with floating point vectors.");

		RF_MATH_ASSERT(tT >= T(0) && tT <= T(1));
		return TRFVector4<T>(
			kVec0.tX + tT * (kVec1.tX - kVec0.tX),
			kVec0.tY + tT * (kVec1.tY - kVec0.tY),
			kVec0.tZ + tT * (kVec1.tZ - kVec0.tZ),
			kVec0.tW + tT * (kVec1.tW - kVec0.tW));
	}

	template <typename T>
	inline TRFVector4<T> VectorSmoothStep(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1, T tT)
	{
		static_assert(std::is_floating_point<T>::value, "VectorSmoothStep only works with floating point vectors.");

		RF_MATH_ASSERT(tT >= T(0) && tT <= T(1));
		return VectorLerp(kVec0, kVec1, tT * tT * (T(3) - T(2) * tT));
	}

	template <typename T>
	inline T VectorLength(const TRFVector4<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorLength only works with floating point vectors.");

		return std::sqrt(VectorLengthSquared(kVec));
	}

	template <typename T>
	inline T VectorLengthSquared(const TRFVector4<T>& kVec)
	{
		return (kVec.tX * kVec.tX) + (kVec.tY * kVec.tY) + (kVec.tZ * kVec.tZ) + (kVec.tW * kVec.tW);
	}

	template <typename T>
	inline TRFVector4<T> VectorReciprocal(const TRFVector4<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorReciprocal only works with floating point vectors.");

		return TRFVector4<T>(
			(std::abs(kVec.tX) > T(0)) ? (T(1) / kVec.tX) : std::numeric_limits<T>::infinity(),
			(std::abs(kVec.tY) > T(0)) ? (T(1) / kVec.tY) : std::numeric_limits<T>::infinity(),
			(std::abs(kVec.tZ) > T(0)) ? (T(1) / kVec.tZ) : std::numeric_limits<T>::infinity(),
			(std::abs(kVec.tW) > T(0)) ? (T(1) / kVec.tW) : std::numeric_limits<T>::infinity());
	}

	template <typename T>
	inline T VectorReciprocalLength(const TRFVector4<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorReciprocalLength only works with floating point vectors.");

		return T(1) / VectorLength(kVec);
	}

	template <typename T>
	inline TRFVector4<T> VectorNormalize(const TRFVector4<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorNormalize only works with floating point vectors.");

		T tLenSqr = VectorLengthSquared(kVec);
		RF_MATH_ASSERT(T(0) != tLenSqr);
		return kVec * (T(1) / std::sqrt(tLenSqr));
	}

	template <typename T>
	inline TRFVector4<T> VectorReflect(const TRFVector4<T>& kIncident, const TRFVector4<T>& kNormal)
	{
		static_assert(std::is_floating_point<T>::value, "VectorReflect only works with floating point vectors.");

		return kIncident - (T(2) * VectorDot(kIncident, kNormal)) * kNormal;
	}

	template <typename T>
	inline TRFVector4<T> VectorRefract(const TRFVector4<T>& kIncident, const TRFVector4<T>& kNormal, T tRefractIndex)
	{	
		static_assert(std::is_floating_point<T>::value, "VectorRefract only works with floating point vectors.");

		T tDot = VectorDot(kNormal, kIncident);
		T tK = T(1) - tRefractIndex * tRefractIndex * (T(1) - tDot * tDot);
		if (tK < T(0))
			return TRFVectors4<T>::ZERO;
		else
			return tRefractIndex * kIncident - (tRefractIndex * tDot + std::sqrt(tK)) * kNormal;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	void VectorComputeExtremesV(uint uiCount, const TRFVector4<T>* pkVectors, TRFVector4<T>& kMin, TRFVector4<T>& kMax)
	{
		RF_MATH_ASSERT_MSG(uiCount > 0 && pkVectors, "Cannot calculate extreme with empty input set.");

		kMin = pkVectors[0];
		kMax = pkVectors[0];
		for (uint ui = 1; ui < uiCount; ++ui)
		{
			const TRFVector4<T>& kVec = pkVectors[ui];

			kMin.tX = std::min(kVec.tX, kMin.tX);
			kMax.tX = std::max(kVec.tX, kMax.tX);
			kMin.tY = std::min(kVec.tY, kMin.tY);
			kMax.tY = std::max(kVec.tY, kMax.tY);
			kMin.tZ = std::min(kVec.tZ, kMin.tZ);
			kMax.tZ = std::max(kVec.tZ, kMax.tZ);
			kMin.tW = std::min(kVec.tW, kMin.tW);
			kMax.tW = std::max(kVec.tW, kMax.tW);
		}
	}

	template <typename T>
	uint VectorIndexOfMaxAbsComponent(const TRFVector4<T>& kVec)
	{
		T tXAbs = std::abs(kVec.tX);
		T tYAbs = std::abs(kVec.tY);
		T tZAbs = std::abs(kVec.tZ);
		T tWAbs = std::abs(kVec.tW);

		if (tXAbs > tYAbs && tXAbs > tZAbs && tXAbs > tWAbs)
			return 0u;
		else if (tYAbs > tZAbs && tYAbs > tWAbs)
			return 1u;
		else if (tZAbs > tWAbs)
			return 2u;
		else
			return 3u;
	}

	template <typename T>
	inline TRFVector4<T> VectorFloor(const TRFVector4<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorFloor only works with floating point vectors.");

		return TRFVector4<T>(std::floor(kVec.tX), std::floor(kVec.tY), std::floor(kVec.tZ), std::floor(kVec.tW));
	}

	template <typename T>
	inline TRFVector4<T> VectorAbs(const TRFVector4<T>& kVec)
	{
		return TRFVector4<T>(std::abs(kVec.tX), std::abs(kVec.tY), std::abs(kVec.tZ), std::abs(kVec.tW));
	}

	template <typename T>
	inline TRFVector4<T> VectorMin(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return TRFVector4<T>(std::min(kVec0.tX, kVec1.tX), std::min(kVec0.tY, kVec1.tY), std::min(kVec0.tZ, kVec1.tZ), std::min(kVec0.tW, kVec1.tW));
	}

	template <typename T>
	inline TRFVector4<T> VectorMax(const TRFVector4<T>& kVec0, const TRFVector4<T>& kVec1)
	{
		return TRFVector4<T>(std::max(kVec0.tX, kVec1.tX), std::max(kVec0.tY, kVec1.tY), std::max(kVec0.tZ, kVec1.tZ), std::max(kVec0.tW, kVec1.tW));
	}

	//-------------------------------------------------------------------------
}