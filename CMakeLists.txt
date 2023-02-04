cmake_minimum_required(VERSION 3.8.0)

# --------------------------------------------------------------------------------

# Global project name.
project (SolidVoxelization)

set (TARGET_NAME "SolidVoxelization")
set (CMAKE_CXX_STANDARD 17)

include_directories (
	Math
	include
)

set (SOURCE_FILES
	main.cpp
	src/RFIntersectionTests.cpp
	src/RFVoxelOctree.cpp
	src/RFVoxelOctreeBuilder.cpp
	Math/TRFVectors.cpp
	include/RFIntersectionTests.h
	include/RFVoxelOctree.h
	include/RFVoxelOctreeBuilder.h
)

# Add definitions.
if (MSVC)
	add_definitions (-D_SCL_SECURE_NO_WARNINGS)
	add_definitions (-D_CRT_SECURE_NO_WARNINGS)	
elseif(CMAKE_COMPILER_IS_GNUCXX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
endif ()

set (ARCH x86)
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
  set (ARCH x64)
endif ()

set (COMPILER Undefined)
if (MSVC10)
	set (COMPILER VC100)
elseif (MSVC11)
	set (COMPILER VC110)
elseif (MSVC12)
	set (COMPILER VC120)
elseif(CMAKE_COMPILER_IS_GNUCXX)
    set (COMPILER GCC)
endif ()


set(EXECUTABLE_OUTPUT_PATH ./)
add_executable (${TARGET_NAME} ${SOURCE_FILES})



