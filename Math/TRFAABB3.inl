namespace RFMath
{
	//------------------------------------------------------------------------- 
	template <typename T>
	inline TRFAABB3<T>::TRFAABB3() :
		kMin(TRFVectors3<T>::MAX),
		kMax(TRFVectors3<T>::MIN)
	{
	}

	template <typename T>
	inline TRFAABB3<T>::TRFAABB3(const TRFAABB3<T>& kAABB) :
		kMin(kAABB.kMin),
		kMax(kAABB.kMax)
	{
	}

	template <typename T>
	inline TRFAABB3<T>::TRFAABB3(const T& tMinX, const T& tMinY, const T& tMinZ, const T& tMaxX, const T& tMaxY, const T& tMaxZ) :
		kMin(tMinX, tMinY, tMinZ),
		kMax(tMaxX, tMaxY, tMaxZ)
	{
	}

	template <typename T>
	inline TRFAABB3<T>::TRFAABB3(const TRFVector3<T>& kMin, const TRFVector3<T>& kMax) :
		kMin(kMin),
		kMax(kMax)
	{
	}

	//------------------------------------------------------------------------- 

	template <typename T>
	template <typename U>
	inline TRFAABB3<T>::TRFAABB3(const TRFAABB3<U>& kAABB) :
		kMin(TRFVector3<T>(kAABB.kMin)),
		kMax(TRFVector3<T>(kAABB.kMax))
	{
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFAABB3<T>& TRFAABB3<T>::operator=(const TRFAABB3<T>& kAABB)
	{
		kMin = kAABB.kMin;
		kMax = kAABB.kMax;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline T TRFAABB3<T>::GetWidth() const
	{
		return (kMax.tX - kMin.tX);
	}

	template <typename T>
	inline T TRFAABB3<T>::GetHeight() const
	{
		return (kMax.tY - kMin.tY);
	}

	template <typename T>
	inline T TRFAABB3<T>::GetDepth() const
	{
		return (kMax.tZ - kMin.tZ);
	}

	template <typename T>
	inline TRFVector3<T> TRFAABB3<T>::GetCenter() const
	{
		return TRFVector3<T>(
			kMin.tX + (GetWidth() * T(0.5)),
			kMin.tY + (GetHeight() * T(0.5)),
			kMin.tZ + (GetDepth() * T(0.5)));
	}

	template <typename T>
	inline void TRFAABB3<T>::GetCenterExtends(TRFVector3<T>& kCenter, T& tExtendsX, T& tExtendsY, T& tExtendsZ) const
	{
		tExtendsX = GetWidth() * T(0.5);
		tExtendsY = GetHeight() * T(0.5);
		tExtendsZ = GetDepth() * T(0.5);
		kCenter.tX = kMin.tX + tExtendsX;
		kCenter.tY = kMin.tY + tExtendsY;
		kCenter.tZ = kMin.tZ + tExtendsZ;
	}

	template <typename T>
	inline TRFVector3<T> TRFAABB3<T>::GetDimensions() const
	{
		return TRFVector3<T>(GetWidth(), GetHeight(), GetDepth());
	}

	template <typename T>
	inline T TRFAABB3<T>::GetMaxDimension() const
	{
		return std::max(std::max(GetWidth(), GetHeight()), GetDepth());
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline bool operator==(const TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1)
	{
		return (kAABB0.kMin == kAABB1.kMin) && (kAABB0.kMax == kAABB1.kMax);
	}

	template <typename T>
	inline bool operator!=(const TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1)
	{
		return (kAABB0.kMin != kAABB1.kMin) || (kAABB0.kMax != kAABB1.kMax);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFAABB3<T>& kAABB)
	{
		kOs << "Min: " << kAABB.kMin << " Max: " << kAABB.kMax;
		return kOs;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFAABB3<T> AABBMerge(const TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1)
	{
		return TRFAABB3<T>(
			std::min(kAABB0.kMin.tX, kAABB1.kMin.tX), std::min(kAABB0.kMin.tY, kAABB1.kMin.tY), std::min(kAABB0.kMin.tZ, kAABB1.kMin.tZ),
			std::max(kAABB0.kMax.tX, kAABB1.kMax.tX), std::max(kAABB0.kMax.tY, kAABB1.kMax.tY), std::max(kAABB0.kMax.tZ, kAABB1.kMax.tZ));
	}

	template <typename T>
	inline TRFAABB3<T> AABBMerge(const TRFAABB3<T>& kAABB, const TRFVector3<T>& kPoint)
	{
		return TRFAABB3<T>(
			std::min(kAABB.kMin.tX, kPoint.tX), std::min(kAABB.kMin.tY, kPoint.tY), std::min(kAABB.kMin.tZ, kPoint.tZ),
			std::max(kAABB.kMax.tX, kPoint.tX), std::max(kAABB.kMax.tY, kPoint.tY), std::max(kAABB.kMax.tZ, kPoint.tZ));
	}

	template <typename T>
	inline void AABBMergeInPlace(TRFAABB3<T>& kAABB0, const TRFAABB3<T>& kAABB1)
	{
			kAABB0.kMin.tX = std::min(kAABB0.kMin.tX, kAABB1.kMin.tX);
			kAABB0.kMin.tY = std::min(kAABB0.kMin.tY, kAABB1.kMin.tY);
			kAABB0.kMin.tZ = std::min(kAABB0.kMin.tZ, kAABB1.kMin.tZ);

			kAABB0.kMax.tX = std::max(kAABB0.kMax.tX, kAABB1.kMax.tX);
			kAABB0.kMax.tY = std::max(kAABB0.kMax.tY, kAABB1.kMax.tY);
			kAABB0.kMax.tZ = std::max(kAABB0.kMax.tZ, kAABB1.kMax.tZ);
	}

	template <typename T>
	inline void AABBMergeInPlace(TRFAABB3<T>& kAABB, const TRFVector3<T>& kPoint)
	{
		kAABB.kMin.tX = std::min(kAABB.kMin.tX, kPoint.tX);
		kAABB.kMin.tY = std::min(kAABB.kMin.tY, kPoint.tY);
		kAABB.kMin.tZ = std::min(kAABB.kMin.tZ, kPoint.tZ);

		kAABB.kMax.tX = std::max(kAABB.kMax.tX, kPoint.tX);
		kAABB.kMax.tY = std::max(kAABB.kMax.tY, kPoint.tY);
		kAABB.kMax.tZ = std::max(kAABB.kMax.tZ, kPoint.tZ);
	}

	//-------------------------------------------------------------------------
}