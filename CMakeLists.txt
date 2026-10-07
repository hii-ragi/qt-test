cmake_minimum_required(VERSION 3.21)

project(ime_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(ime-test
    test.cpp
)

target_link_libraries(ime-test PRIVATE Qt6::Widgets)
