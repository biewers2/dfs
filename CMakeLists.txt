cmake_minimum_required(VERSION 3.10)
project(dfs VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
file(GLOB SERVER_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/server/*.cpp)
file(GLOB CLIENT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/client/*.cpp)
file(GLOB SOCKIO_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/sockio/*.cpp)

add_executable(server ${SERVER_SOURCE_FILES} ${SOCKIO_SOURCE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES} ${SOCKIO_SOURCE_FILES})
install(TARGETS server client DESTINATION ${PROJECT_SOURCE_DIR}/bin)

target_include_directories(server PUBLIC "include")
target_include_directories(client PUBLIC "include")


