cmake_minimum_required(VERSION 3.24)

PROJECT(RVWeb)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF) 

find_package(Boost 1.45.0 COMPONENTS serialization)

    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(RVWeb src/main.cpp src/RVConfig.cpp src/RVConfig.hpp src/Strategy.cpp src/Strategy.hpp src/Property.cpp src/Property.hpp src/Well.cpp src/Well.hpp src/WellList.cpp src/WellList.hpp src/IJKKey.cpp src/IJKKey.hpp src/Clustering.cpp src/Clustering.hpp ) 
    target_link_libraries(RVWeb ${Boost_LIBRARIES})



