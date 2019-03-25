cmake_minimum_required(VERSION 3.7.1 FATAL_ERROR)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(verse_accumulator
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.ui)
target_link_libraries(verse_accumulator PRIVATE Qt5::Widgets)
