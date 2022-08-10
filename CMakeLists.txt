CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(RVWeb)

FIND_PACKAGE( Boost 1.74.0 REQUIRED COMPONENTS iostreams filesystem serialization)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
ADD_EXECUTABLE(rvweb src/main.cpp src/CSVParser.cpp src/RVConfig.cpp src/SnakeCurve.cpp)
TARGET_LINK_LIBRARIES(rvweb Boost::filesystem Boost::iostreams Boost::serialization)
