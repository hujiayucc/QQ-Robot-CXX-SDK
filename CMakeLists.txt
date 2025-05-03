cmake_minimum_required(VERSION 3.30)
project(main CXX)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

add_definitions(-DTEST_EXPORTS)
add_library(main SHARED main.cpp Api.h
        helper.cpp
        type.h
)
add_executable(Test test.cpp)
if(MSVC)
    target_compile_options(main PRIVATE /MT)
endif()