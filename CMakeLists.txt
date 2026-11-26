cmake_minimum_required(VERSION 3.5)
project(main)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


add_subdirectory(src/app/)
add_subdirectory(src/cal/)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")


include(cmake/algorithm_options.cmake)

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


if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test/)
endif()