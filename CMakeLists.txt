cmake_minimum_required(VERSION 3.24)

PROJECT(RVWeb)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Users/k/Documents/Softwares/boost/boost_1_79_0/tools/cmake/include")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/Users/k/Documents/Softwares/boost/boost_1_79_0/libs")
set(BOOST_ROOT "C:/Users/k/Documents/Softwares/boost/boost_1_79_0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --sysroot=${SYSROOT}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --sysroot=${SYSROOT} -I${SYSROOT}/include/libcxx")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS}")
set(CMAKE_FIND_ROOT_PATH "${SYSROOT}")

find_package(Boost 1.45.0 COMPONENTS serialization)

    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(RVWeb src/main.cpp src/RVConfig.cpp src/RVConfig.hpp src/Strategy.cpp src/Strategy.hpp src/Property.cpp src/Property.hpp) 
    target_link_libraries(RVWeb ${Boost_LIBRARIES})



