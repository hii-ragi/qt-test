cmake_minimum_required(VERSION 3.21)

project(ime_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(QT_VERSION_MAJOR "6" CACHE STRING "Qt major version (5 or 6)")
if(NOT QT_VERSION_MAJOR MATCHES "^[56]$")
    message(FATAL_ERROR "QT_VERSION_MAJOR must be 5 or 6")
endif()
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_add_executable(ime-test test.cpp)
else()
    add_executable(ime-test test.cpp)
endif()

target_link_libraries(ime-test PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
