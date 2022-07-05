cmake_minimum_required(VERSION 3.5)

project(RVWeb)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(rvweb src/main.cpp src/CSVParser.cpp)
