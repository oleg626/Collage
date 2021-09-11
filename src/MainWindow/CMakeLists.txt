cmake_minimum_required(VERSION 2.8)

project(MainWindow)

set(SOURCE_LIB
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui)

add_library(MainWindow STATIC ${SOURCE_LIB})# Создание статической библиотеки

target_link_libraries(MainWindow
    PRIVATE
    Qt5::Widgets
)
