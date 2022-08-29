CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(RVWeb)

FIND_PACKAGE( Boost 1.74.0 REQUIRED COMPONENTS iostreams filesystem serialization)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
ADD_EXECUTABLE(rvweb src/main.cpp src/CSVParser.cpp src/SnakeCurve.cpp src/IJKKey.cpp src/Strategy.cpp src/Property.cpp src/Clustering.cpp src/Pixelization.cpp src/Metadata.hpp src/Metadata.cpp)
TARGET_LINK_LIBRARIES(rvweb Boost::filesystem Boost::iostreams Boost::serialization)
