namespace RFMath
{
	//------------------------------------------------------------------------- 

	template <typename T>
	inline TRFRay3<T>::TRFRay3() :
		kOrigin(TRFVectors3<T>::ZERO),
		kDirection(TRFVectors3<T>::UNIT_X)
	{
		static_assert(std::is_floating_point<T>::value, "Only floating point rays exist.");
	}

	template <typename T>
	inline TRFRay3<T>::TRFRay3(const TRFRay3<T>& kRay) :
		kOrigin(kRay.kOrigin),
		kDirection(kRay.kDirection),
		kInvDirection(kRay.kInvDirection),
		kOod(kRay.kOod),
		kSigns(kRay.kSigns)
	{
	}

	template <typename T>
	inline TRFRay3<T>::TRFRay3(T tOriginX, T tOriginY, T tOriginZ, T tDirectionX, T tDirectionY, T tDirectionZ) :
		kOrigin(TRFVector3<T>(tOriginX, tOriginY, tOriginZ)),
		kDirection(TRFVector3<T>(tDirectionX, tDirectionY, tDirectionZ))
	{
		static_assert(std::is_floating_point<T>::value, "Only floating point rays exist.");
		
		kSigns = TRFVector3<T>((kDirection.tX < T(0)) ? T(-1) : T(1),
			                   (kDirection.tY < T(0)) ? T(-1) : T(1),
			                   (kDirection.tZ < T(0)) ? T(-1) : T(1));

		kInvDirection = VectorReciprocal(kDirection);
		kOod = TRFVector3<T>(kInvDirection.tX * kOrigin.tX, kInvDirection.tY * kOrigin.tY, kInvDirection.tZ * kOrigin.tZ);
	}

	template <typename T>
	inline TRFRay3<T>::TRFRay3(const TRFVector3<T>& kOrigin, const TRFVector3<T>& kDirection) :
		kOrigin(TRFVector3<T>(kOrigin)),
		kDirection(TRFVector3<T>(kDirection))
	{
		static_assert(std::is_floating_point<T>::value, "Only floating point rays exist.");

		kSigns = TRFVector3<T>((kDirection.tX < T(0)) ? T(-1) : T(1),
		                       (kDirection.tY < T(0)) ? T(-1) : T(1),
			                   (kDirection.tZ < T(0)) ? T(-1) : T(1));

		kInvDirection = VectorReciprocal(kDirection);
		kOod = TRFVector3<T>(kInvDirection.tX * kOrigin.tX, kInvDirection.tY * kOrigin.tY, kInvDirection.tZ * kOrigin.tZ);		               
	}

	//-------------------------------------------------------------------------

	template <typename T>
	template <typename U>
	inline TRFRay3<T>::TRFRay3(const TRFRay3<U>& kRay) :
		kOrigin(TRFVector3<T>(kRay.kOrigin)),
		kDirection(TRFVector3<T>(kRay.kDirection)),
		kInvDirection(TRFVector3<T>(kRay.kInvDir)),
		kOod(TRFVector3<T>(kRay.kOod)),
		kSigns(TRFVector3<T>(kRay.kSigns))
	{
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline T* TRFRay3<T>::Data()
	{
		return &kOrigin;
	}

	template <typename T>
	inline const T* TRFRay3<T>::Data() const
	{
		return &kOrigin;
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline TRFRay3<T>& TRFRay3<T>::operator=(const TRFRay3<T>& kRay)
	{
		kOrigin    = kRay.kOrigin;
		kDirection = kRay.kDirection;
		kInvDirection    = kRay.kInvDir;
		kOod       = kRay.kOod;
		kSigns     = kRay.kSigns;
		return *this;
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline TRFRay3<T> operator-(const TRFRay3<T>& kRay)
	{
		static_assert(std::is_signed<T>::value, "Only works on signed types.");

		return TRFRay3<T>(kRay.kOrigin, -kRay.kDirection);
	}

	//-------------------------------------------------------------------------

	template <typename T> 
	inline bool operator==(const TRFRay3<T>& kRay0, const TRFRay3<T>& kRay1)
	{
		return (RFMemcmp(kRay0.Data(), kRay1.Data(), sizeof(TRFRay3<T>)) == 0);
	}

	template <typename T>
	inline bool operator!=(const TRFRay3<T>& kRay0, const TRFRay3<T>& kRay1)
	{
		return (RFMemcmp(kRay0.Data(), kRay1.Data(), sizeof(TRFRay3<T>)) != 0);
	}

	//-------------------------------------------------------------------------

	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFRay3<T>& kRay)
	{
		kOs << kRay.kOrigin << std::endl;
		kOs << kRay.kDirection;
		kOs << kRay.kSigns << std::endl;
		return kOs;
	}

	//-------------------------------------------------------------------------
}
