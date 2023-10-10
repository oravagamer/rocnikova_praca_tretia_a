cmake_minimum_required(VERSION 3.25)
project(console-pong-game CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(source_folder ${CMAKE_SOURCE_DIR}/res)
set(target_folder ${CMAKE_BINARY_DIR}/res)

find_package(SFML REQUIRED COMPONENTS graphics window system audio)
file(GLOB SRC */*.cpp)
link_libraries(sfml-graphics sfml-window sfml-system sfml-audio)
add_library(ProjectLib STATIC ${SRC})
include_directories(${SFML_INCLUDE_DIR})
include_directories(./)

add_executable(console-pong-game main.cpp)
add_custom_command(
    TARGET console-pong-game
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${source_folder}
            ${target_folder}
)
target_sources(console-pong-game PRIVATE "res/American Captain.ttf")

target_link_libraries(console-pong-game ProjectLib ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})