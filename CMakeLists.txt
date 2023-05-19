cmake_minimum_required(VERSION 2.8.12)

project(LEDTool LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_FLAGS "-Werror -Wfatal-errors -Wpedantic -Wall -Wextra")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_subdirectory(DeTimefeqLayout)
add_subdirectory(EnTimefeqLayout)
add_subdirectory(DeColorLayout)
add_subdirectory(EnColorLayout)

add_executable(${PROJECT_NAME}
    "mainwindow.cpp"
    "main.cpp"
    ${CMAKE_CURRENT_SOURCE_DIR}/icon/icon.rc
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
    DeTimefeqLayout
    EnTimefeqLayout
    DeColorLayout
    EnColorLayout
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
)
