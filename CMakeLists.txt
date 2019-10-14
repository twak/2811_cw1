cmake_minimum_required(VERSION 3.15)
project(lab1)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_executable(lab1 main.cpp card.cpp card.h)

target_link_libraries(lab1 ${QT_LIBRARIES})