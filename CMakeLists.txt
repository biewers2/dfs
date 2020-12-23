cmake_minimum_required(VERSION 3.10)
project(dfs VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(server server/*.cpp sockio/*.cpp)
add_executable(client client/*.cpp z)

target_include_directories(server PUBLIC "include")
target_include_directories(client PUBLIC "include")
