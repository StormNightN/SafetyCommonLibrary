cmake_minimum_required(VERSION 3.7)
project(SafetyCommon)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)

if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -O2")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wpedantic -pedantic")
endif()

set(SOURCES Networking.cpp CommonSSL.cpp)
add_library(SafetyCommon SHARED ${SOURCES})

target_include_directories(SafetyCommon INTERFACE include)
target_link_libraries(${PROJECT_NAME} ssl crypto)