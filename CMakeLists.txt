cmake_minimum_required(VERSION 3.10)
project(dfs VERSION 0.1)
enable_testing()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE API_UNIT_TEST_FILES
        ${PROJECT_SOURCE_DIR}/test/api/*.cpp)
file(GLOB_RECURSE API_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/api/*.cpp
        ${API_UNIT_TEST_FILES})
file(GLOB SERVER_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/server/*.cpp
        ${API_SOURCE_FILES})
file(GLOB CLIENT_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/client/*.cpp
        ${API_SOURCE_FILES})

file(COPY ${PROJECT_SOURCE_DIR}/test/mock-fs DESTINATION ${CMAKE_BINARY_DIR}/bin)

add_executable(server
        ${SERVER_SOURCE_FILES}
        ${API_SOURCE_FILES})
add_executable(client
        ${CLIENT_SOURCE_FILES}
        ${API_SOURCE_FILES})
add_executable(api_unit_tests
        ${API_SOURCE_FILES})

target_include_directories(server
        PUBLIC "include"
        PRIVATE "src/api"
        PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(client
        PUBLIC "include"
        PRIVATE "src/api"
        PRIVATE ${PROJECT_SOURCE_DIR})
target_include_directories(api_unit_tests
        PUBLIC "include"
        PRIVATE "src/api"
        PRIVATE ${PROJECT_SOURCE_DIR})

target_link_libraries(api_unit_tests
        ${CONAN_LIBS})
