cmake_minimum_required(VERSION 3.15)
project(cw1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_executable(cw1 responsive_layout.cpp responsive_layout.h responsive_label.cpp responsive_label.h responsive_window.cpp responsive_window.h screenshot.cpp screenshot.h)

target_link_libraries(cw1 ${QT_LIBRARIES})
