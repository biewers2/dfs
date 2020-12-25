cmake_minimum_required(VERSION 3.10)
project(dfs VERSION 0.1)
enable_testing()

#include(${PROJECT_SOURCE_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Primary Executables

file(GLOB SERVER_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/server/*.cpp)
file(GLOB CLIENT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/client/*.cpp)
file(GLOB SOCKIO_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/api/sockio/*.cpp)
file(GLOB FS_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/api/fs/*.cpp)

add_executable(server ${SERVER_SOURCE_FILES} ${SOCKIO_SOURCE_FILES} ${FS_SOURCE_FILES})
add_executable(client ${CLIENT_SOURCE_FILES} ${SOCKIO_SOURCE_FILES} ${FS_SOURCE_FILES})

target_include_directories(server PUBLIC "include" "src/api")
target_include_directories(client PUBLIC "include" "src/api")


# Testing

#file(GLOB SERVER_UNIT_TEST_FILES ${PROJECT_SOURCE_DIR}/test/api/*.cpp)
#file(GLOB CLIENT_UNIT_TEST_FILES ${PROJECT_SOURCE_DIR}/test/api/*.cpp)
#file(GLOB API_UNIT_TEST_FILES ${PROJECT_SOURCE_DIR}/test/api/*.cpp)
#
#add_executable(server_unit_tests ${SERVER_UNIT_TEST_FILES})
#add_executable(client_unit_tests ${CLIENT_UNIT_TEST_FILES})
#add_executable(api_unit_tests ${API_UNIT_TEST_FILES})
#target_link_libraries(server_unit_tests ${CONAN_LIBS})
#target_link_libraries(client_unit_tests ${CONAN_LIBS})
#target_link_libraries(api_unit_tests ${CONAN_LIBS})
#
#add_test(NAME server_unit_tests
#        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
#        COMMAND server_unit_tests)
#add_test(NAME client_unit_tests
#        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
#        COMMAND client_unit_tests)
#add_test(NAME api_unit_tests
#        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
#        COMMAND api_unit_tests)
