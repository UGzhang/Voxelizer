#pragma once

#include <fstream>
#include "TRFVectors.h"
#include "TRFVector3.h"

namespace RFMath
{
	template <typename T>
	struct TRFRay3
	{
		// Typedefs.
		typedef TRFRay3<T> type;
		typedef T value_type;

		// Data.
		TRFVector3<T> kOrigin;
		TRFVector3<T> kDirection;
		TRFVector3<T> kInvDirection;
		TRFVector3<T> kOod;
		TRFVector3<T> kSigns;

		// Constructors.
		inline TRFRay3();
		inline TRFRay3(const TRFRay3<T>& kRay);
		inline TRFRay3(T tOriginX, T tOriginY, T tOriginZ, T tDirectionX, T tDirectionY, T tDirectionZ);
		inline TRFRay3(const TRFVector3<T>& kOrigin, const TRFVector3<T>& kDirection);

		// Conversion constructors.
		template <typename U>
		explicit inline TRFRay3(const TRFRay3<U>& kRay);		

		// Data pointer access.
		inline T* Data();
		inline const T* Data() const;

		// Unary arithmetic operators.
		inline TRFRay3<T>& operator=(const TRFRay3<T>& kRay);
	};

	// Unary constant operators.
	template <typename T> 
	inline TRFRay3<T> operator-(const TRFRay3<T>& kRay);

	// Binary operators.
	template <typename T> 
	inline bool operator==(const TRFRay3<T>& kRay0, const TRFRay3<T>& kRay1);
	template <typename T>
	inline bool operator!=(const TRFRay3<T>& kRay0, const TRFRay3<T>& kRay1);	

	// Streaming.
	template <typename T>
	inline std::ostream& operator<<(std::ostream& kOs, const TRFRay3<T>& kRay);

	// Size types.
	typedef TRFRay3<float> RFRay3f;
	typedef TRFRay3<double> RFRay3d;
}

#include "TRFRay3.inl"