cmake_minimum_required(VERSION 3.24)

PROJECT(RVWeb)

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and 
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs 
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF) 
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Users/k/Documents/Softwares/boost_1_79_0")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/Users/k/Documents/Softwares/boost_1_79_0")

FIND_PACKAGE(Boost COMPONENTS filesystem iostreams serialization)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" ) 
    INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
    ADD_EXECUTABLE(rvweb src/main.cpp src/CSVParser.cpp src/RVConfig.cpp src/Metadata.hpp)
    TARGET_LINK_LIBRARIES(rvweb Boost::filesystem Boost::iostreams Boost::serialization)
endif()



