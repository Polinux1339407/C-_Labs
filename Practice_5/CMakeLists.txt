cmake_minimum_required(VERSION 3.23)
project(untitled1)

SET Qt5_DIR= = "C:\Qt\Tools\QtDesignStudio\qt5_design_studio_reduced_version\lib\cmake\Qt5"
set(CMAKE_PREFIX_PATH "$ENV{QTDIR}")


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled1 main.cpp MainWindow.cpp MainWindow.h MyPainter.cpp MyPainter.h Signal.cpp Signal.h)
target_link_libraries(untitled1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

