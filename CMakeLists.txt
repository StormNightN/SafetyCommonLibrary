cmake_minimum_required(VERSION 3.7)
project(SafetyCommon)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)

add_library(SafetyCommon SHARED include/CommonSSLFunctions.h CommonSSLFunctions.cpp)
target_include_directories(SafetyCommon INTERFACE include)
target_link_libraries(${PROJECT_NAME} ssl crypto)
