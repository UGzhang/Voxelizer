namespace RFMath
{
	//------------------------------------------------------------------------- 

	template <typename T>
	inline TRFVector2<T>::TRFVector2() :
		tX(T(0)),
		tY(T(0))
	{
	}

	template <typename T>
	inline TRFVector2<T>::TRFVector2(const TRFVector2<T>& kVec) :
		tX(kVec.tX),
		tY(kVec.tY)
	{
	}

	template <typename T>
	inline TRFVector2<T>::TRFVector2(T tValue) :
		tX(tValue),
		tY(tValue)
	{
	}

	template <typename T>
	inline TRFVector2<T>::TRFVector2(T tX, T tY) :
		tX(tX),
		tY(tY)
	{
	}

	template <typename T>
	inline TRFVector2<T>::TRFVector2(T tData[2]) :
		tX(tData[0]),
		tY(tData[1])
	{
	}

	//-------------------------------------------------------------------------

	template <typename T>
	template <typename U>
	inline TRFVector2<T>::TRFVector2(const TRFVector2<U>& kVec) :
		tX(T(kVec.tX)),
		tY(T(kVec.tY))
	{
	}

	//------------------------------------------------------------------------- 

	template <typename T>
	inline T& TRFVector2<T>::operator[](int i)
	{
        this->RF_MATH_ASSERT(i >= 0 && i < 2);
		return Data()[i];
	}

	template <typename T>
	inline T TRFVector2<T>::operator[](int i) const
	{
		this->RF_MATH_ASSERT(i >= 0 && i < 2);
		return Data()[i];
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline T* TRFVector2<T>::Data()
	{
		return &tX;
	}

	template <typename T>
	inline const T* TRFVector2<T>::Data() const
	{
		return &tX;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator=(const TRFVector2<T>& kVec)
	{
		tX = kVec.tX;
		tY = kVec.tY;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator+=(T tValue)
	{
		tX += tValue;
		tY += tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator+=(const TRFVector2<T>& kVec)
	{
		tX += kVec.tX;
		tY += kVec.tY;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator-=(T tValue)
	{
		tX -= tValue;
		tY -= tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator-=(const TRFVector2<T>& kVec)
	{
		tX -= kVec.tX;
		tY -= kVec.tY;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator*=(T tValue)
	{
		tX *= tValue;
		tY *= tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator*=(const TRFVector2<T>& kVec)
	{
		tX *= kVec.tX;
		tY *= kVec.tY;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator/=(T tValue)
	{
		tX /= tValue;
		tY /= tValue;
		return *this;
	}

	template <typename T>
	inline TRFVector2<T>& TRFVector2<T>::operator/=(const TRFVector2<T>& kVec)
	{
		tX /= kVec.tX;
		tY /= kVec.tY;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T> operator+(const TRFVector2<T>& kVec, T tValue)
	{
		return TRFVector2<T>(kVec.tX + tValue, kVec.tY + tValue);
	}

	template <typename T>
	inline TRFVector2<T> operator+(T tValue, const TRFVector2<T>& kVec)
	{
		return TRFVector2<T>(tValue + kVec.tX, tValue + kVec.tY);
	}

	template <typename T> 
	inline TRFVector2<T> operator+(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return TRFVector2<T>(kVec0.tX + kVec1.tX, kVec0.tY + kVec1.tY);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T> operator-(const TRFVector2<T>& kVec, T tValue)
	{
		return TRFVector2<T>(kVec.tX - tValue, kVec.tY - tValue);
	}

	template <typename T>
	inline TRFVector2<T> operator-(T tValue, const TRFVector2<T>& kVec)
	{
		return TRFVector2<T>(tValue - kVec.tX, tValue - kVec.tY);
	}

	template <typename T> 
	inline TRFVector2<T> operator-(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return TRFVector2<T>(kVec0.tX - kVec1.tX, kVec0.tY - kVec1.tY);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T> operator*(const TRFVector2<T>& kVec, T tValue)
	{
		return TRFVector2<T>(kVec.tX * tValue, kVec.tY * tValue);
	}

	template <typename T>
	inline TRFVector2<T> operator*(T tValue, const TRFVector2<T>& kVec)
	{
		return TRFVector2<T>(tValue * kVec.tX, tValue * kVec.tY);
	}

	template <typename T> 
	inline TRFVector2<T> operator*(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return TRFVector2<T>(kVec0.tX * kVec1.tX, kVec0.tY * kVec1.tY);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFVector2<T> operator/(const TRFVector2<T>& kVec, T tValue)
	{
		return TRFVector2<T>(kVec.tX / tValue, kVec.tY / tValue);
	}

	template <typename T>
	inline TRFVector2<T> operator/(T tValue, const TRFVector2<T>& kVec)
	{
		return TRFVector2<T>(tValue / kVec.tX, tValue / kVec.tY);
	}

	template <typename T> 
	inline TRFVector2<T> operator/(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return TRFVector2<T>(kVec0.tX / kVec1.tX, kVec0.tY / kVec1.tY);
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline TRFVector2<T> operator-(const TRFVector2<T>& kVec)
	{
		static_assert(std::is_signed<T>::value, "operator- only works on signed types.");

		return TRFVector2<T>(-kVec.tX, -kVec.tY);
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline bool operator==(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return (RFMemcmp(kVec0.Data(), kVec1.Data(), sizeof(TRFVector2<T>)) == 0);
	}

	template <typename T>
	inline bool operator!=(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return (RFMemcmp(kVec0.Data(), kVec1.Data(), sizeof(TRFVector2<T>)) != 0);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFVector2<T>& kVec)
	{
		kOs << "(" << kVec.tX << ", " << kVec.tY << ")";
		return kOs;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline T VectorAngleBetweenNormals(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		static_assert(std::is_floating_point<T>::value, "VectorAngleBetweenNormals only works with floating point vectors.");

		return std::acos(VectorDot(kVec0, kVec1));
	}

	template <typename T>
	inline T VectorAngleBetweenVectors(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		static_assert(std::is_floating_point<T>::value, "VectorAngleBetweenVectors only works with floating point vectors.");

		return std::acos(VectorDot(kVec0, kVec1) / (VectorLength(kVec0) * VectorLength(kVec1)));
	}

	template <typename T>
	inline TRFVector2<T> VectorClamp(const TRFVector2<T>& kVec, T tMin, T tMax)
	{
		return TRFVector2<T>(
			RFClamp(kVec.tX, tMin, tMax),
			RFClamp(kVec.tY, tMin, tMax));
	}

	template <typename T>
	inline TRFVector2<T> VectorClampLength(const TRFVector2<T>& kVec, T tMinLength, T tMaxLength)
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
	inline TRFVector2<T> VectorCross(const TRFVector2<T>& kVec)
	{
		return TRFVector2<T>(-kVec.tY, kVec.tX);
	}

	template <typename T>
	inline T VectorDot(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return (kVec0.tX * kVec1.tX) + (kVec0.tY * kVec1.tY);
	}

	template <typename T>
	inline TRFVector2<T> VectorLerp(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1, T tT)
	{
		static_assert(std::is_floating_point<T>::value, "VectorLerp only works with floating point vectors.");
		
		RF_MATH_ASSERT(tT >= T(0) && tT <= T(1));
		return TRFVector2<T>(
			kVec0.tX + tT * (kVec1.tX - kVec0.tX),
			kVec0.tY + tT * (kVec1.tY - kVec0.tY));
	}

	template <typename T>
	inline TRFVector2<T> VectorSmoothStep(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1, T tT)
	{
		static_assert(std::is_floating_point<T>::value, "VectorSmoothStep only works with floating point vectors.");
		
		RF_MATH_ASSERT(tT >= T(0) && tT <= T(1));
		return VectorLerp(kVec0, kVec1, tT * tT * (T(3) - T(2) * tT));
	}

	template <typename T>
	inline T VectorLength(const TRFVector2<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorLength only works with floating point vectors.");
		
		return std::sqrt(VectorLengthSquared(kVec));
	}

	template <typename T>
	inline T VectorLengthSquared(const TRFVector2<T>& kVec)
	{
		return (kVec.tX * kVec.tX) + (kVec.tY * kVec.tY);
	}

	template <typename T>
	inline TRFVector2<T> VectorReciprocal(const TRFVector2<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorReciprocal only works with floating point vectors.");
		
		return TRFVector2<T>(
			(std::abs(kVec.tX) > T(0)) ? (T(1) / kVec.tX) : std::numeric_limits<T>::infinity(),
			(std::abs(kVec.tY) > T(0)) ? (T(1) / kVec.tY) : std::numeric_limits<T>::infinity());
	}

	template <typename T>
	inline T VectorReciprocalLength(const TRFVector2<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorReciprocalLength only works with floating point vectors.");

		return T(1) / VectorLength(kVec);
	}

	template <typename T>
	inline TRFVector2<T> VectorNormalize(const TRFVector2<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorNormalize only works with floating point vectors.");

		T tLenSqr = VectorLengthSquared(kVec);
		RF_MATH_ASSERT(T(0) != tLenSqr);
		return kVec * (T(1) / std::sqrt(tLenSqr));
	}

	template <typename T>
	inline TRFVector2<T> VectorReflect(const TRFVector2<T>& kIncident, const TRFVector2<T>& kNormal)
	{
		static_assert(std::is_floating_point<T>::value, "VectorReflect only works with floating point vectors.");

		return kIncident - (T(2) * VectorDot(kIncident, kNormal)) * kNormal;
	}

	template <typename T>
	inline TRFVector2<T> VectorRefract(const TRFVector2<T>& kIncident, const TRFVector2<T>& kNormal, T tRefractIndex)
	{	
		static_assert(std::is_floating_point<T>::value, "VectorRefract only works with floating point vectors.");

		T tDot = VectorDot(kNormal, kIncident);
		T tK = T(1) - tRefractIndex * tRefractIndex * (T(1) - tDot * tDot);
		if (tK < T(0))
			return TRFVectors2<T>::ZERO;
		else
			return tRefractIndex * kIncident - (tRefractIndex * tDot + std::sqrt(tK)) * kNormal;
	}

	//-------------------------------------------------------------------------
	
	template <typename T>
	void VectorComputeExtremesV(uint uiCount, const TRFVector2<T>* pkVectors, TRFVector2<T>& kMin, TRFVector2<T>& kMax)
	{
		RF_MATH_ASSERT_MSG(uiCount > 0 && pkVectors, "Cannot calculate extreme with empty input set.");

		kMin = pkVectors[0];
		kMax = pkVectors[0];
		for (uint ui = 1; ui < uiCount; ++ui)
		{
			const TRFVector2<T>& kVec = pkVectors[ui];

			kMin.tX = std::min(kVec.tX, kMin.tX);
			kMax.tX = std::max(kVec.tX, kMax.tX);
			kMin.tY = std::min(kVec.tY, kMin.tY);
			kMax.tY = std::max(kVec.tY, kMax.tY);
		}
	}

	template <typename T>
	uint VectorIndexOfMaxAbsComponent(const TRFVector2<T>& kVec)
	{
		return (std::abs(kVec.tX) > std::abs(kVec.tY)) ? 0u : 1u;
	}

	template <typename T>
	inline TRFVector2<T> VectorFloor(const TRFVector2<T>& kVec)
	{
		static_assert(std::is_floating_point<T>::value, "VectorFloor only works with floating point vectors.");

		return TRFVector2<T>(std::floor(kVec.tX), std::floor(kVec.tY));
	}

	template <typename T>
	inline TRFVector2<T> VectorAbs(const TRFVector2<T>& kVec)
	{
		return TRFVector2<T>(std::abs(kVec.tX), std::abs(kVec.tY));
	}

	template <typename T>
	inline TRFVector2<T> VectorMin(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return TRFVector2<T>(std::min(kVec0.tX, kVec1.tX), std::min(kVec0.tY, kVec1.tY));
	}

	template <typename T>
	inline TRFVector2<T> VectorMax(const TRFVector2<T>& kVec0, const TRFVector2<T>& kVec1)
	{
		return TRFVector2<T>(std::max(kVec0.tX, kVec1.tX), std::max(kVec0.tY, kVec1.tY));
	}

	//-------------------------------------------------------------------------
}