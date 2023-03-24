cmake_minimum_required(VERSION 3.24)
project(qtdemo01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/Qt/5.15.2/gcc_64/")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qtdemo01
        main.cpp
        window.h
        window.cpp
        ComputeIP.h
        lib.h)
target_link_libraries(qtdemo01
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

