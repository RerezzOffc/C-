cmake_minimum_required(VERSION 3.10)
project(CPPWebsite)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_website src/main.cpp)

# Tambahkan dependensi cpp-httplib
include_directories(${CMAKE_SOURCE_DIR}/libs)
