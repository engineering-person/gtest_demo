cmake_minimum_required(VERSION 3.5)
project(main)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(test/)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
aux_source_directory(src/ SRC_LIST)
add_executable(main ${SRC_LIST})

# 

if(MY_CMAKE_BUILD_FLAGS STREQUAL "real")
    add_compile_definitions(
        REAL
    )
elseif(MY_CMAKE_BUILD_FLAGS STREQUAL "mojoco")
    add_compile_definitions(
        MOJOCO
    )
elseif(MY_CMAKE_BUILD_FLAGS STREQUAL "gazebo")
    add_compile_definitions(
        GAZEBO
    )
endif()
