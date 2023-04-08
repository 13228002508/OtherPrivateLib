# 要求的cmake最小版本
cmake_minimum_required(VERSION 3.1)

#工程名字
project("TestProc")

#设置QT6的CMake路径
set(CMAKE_PREFIX_PATH $ENV{QT632}/lib/cmake)

find_package(Qt6 6.3.2 REQUIRED COMPONENTS Core Widgets Gui Network )

include_directories(${Qt6Widgets_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp  MyMainWindow.h  MyMainWindow.cpp )

#设置开启QT的元对象系统
set_target_properties(${PROJECT_NAME} PROPERTIES AUTOMOC TRUE AUTOUIC TRUE AUTORCC TRUE)

# Use the widgets module from Qt 6
target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Widgets
                                              Qt6::Core
                                              Qt6::Gui
                                              Qt6::Network                                     
                                              )