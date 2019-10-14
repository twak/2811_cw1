cmake_minimum_required(VERSION 3.15)
project(cw1)

set(CMAKE_CXX_STANDARD 14)
find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
add_executable(cw1 ResponsiveLayout.cpp ResponsiveLayout.h ResponsiveLabel.cpp ResponsiveLabel.h ResponsiveWindow.cpp ResponsiveWindow.h)

target_link_libraries(cw1 ${QT_LIBRARIES})