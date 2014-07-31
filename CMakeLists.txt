PROJECT(inspect_orf)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
if(COMMAND cmake_policy)
      cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
set(CMAKE_BUILD_TYPE Debug)

## Add src and target
ADD_EXECUTABLE(Main orf.cpp utils.cpp main.cpp)

## Add MESA SR libaries
FIND_PATH( MESASR_INCLUDE_PATH libMesaSR.h
	/usr/include
	/usr/local/include
	/sw/include
	/opt/local/include
	DOC "The directory where libMesaSR.h resides")
FIND_LIBRARY( MESASR_LIBRARY
	NAMES mesasr
	PATHS
	/usr/lib64
	/usr/lib
	/usr/local/lib64
	/usr/local/lib
	/sw/lib
	/opt/local/lib
	DOC "The MESASR library")
TARGET_LINK_LIBRARIES(Main ${MESASR_LIBRARY})
INCLUDE_DIRECTORIES(${MESASR_INCLUDE_PATH})

## Add OpenCV
find_package(OpenCV REQUIRED)
TARGET_LINK_LIBRARIES(Main ${OpenCV_LIBS})