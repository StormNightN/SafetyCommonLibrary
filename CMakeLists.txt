cmake_minimum_required(VERSION 3.7)
project(SafetyCommon)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenSSL REQUIRED)

add_library(SafetyCommon main.cpp
        CommonSSLFunctions.h CommonSSLFunctions.cpp)
target_link_libraries(${PROJECT_NAME} OpenSSL::Crypto)
