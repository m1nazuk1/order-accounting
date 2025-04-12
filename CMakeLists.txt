cmake_minimum_required(VERSION 3.5)
project(OrdersApp)
set(CMAKE_CXX_STANDARD 17)
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(OrdersApp
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        adddialog.cpp
        adddialog.h
        adddialog.ui
)

target_link_libraries(OrdersApp PRIVATE Qt5::Widgets Qt5::Core Qt5::Gui)