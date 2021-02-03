cmake_minimum_required(VERSION 3.19.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(leet)
add_executable(leet src/main.cpp)
target_include_directories(leet
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
