cmake_minimum_required(VERSION 3.0)

project(Collage LANGUAGES CXX)

set(CMAKE_CONFIGURATION_TYPES "Release;Debug" CACHE STRING "" FORCE)


add_subdirectory(${SOURCE_DIR}/build_opencv)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
set("OpenCV_DIR" src/build_opencv)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(OpenCV REQUIRED)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(${PROJECT_NAME} WIN32 src/main.cpp)
add_subdirectory(${SOURCE_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${SOURCE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt5::Widgets
        MainWindow
        ${OpenCV_LIBS}
        )

