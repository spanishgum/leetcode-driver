cmake_minimum_required(VERSION 3.19.3)
project(leetcode-driver)

add_definitions("-std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(leet src/main.cpp)
target_link_libraries(leet ${CONAN_LIBS})