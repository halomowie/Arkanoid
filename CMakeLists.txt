cmake_minimum_required(VERSION 3.12)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 14)

add_executable(Arkanoid main.cpp background.cpp background.h paddle.cpp paddle.h ball.cpp ball.h LevelDraw.cpp LevelDraw.h)

set(SFML_PATH "C:/cpp/SFML-2.5.1" ${CMAKE_MODULE_PATH})
set(SFML_DIR ${SFML_PATH}/lib/cmake/SFML)
find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    target_link_libraries(Arkanoid sfml-graphics sfml-window sfml-audio)
    include_directories(${SFML_PATH}/include/SFML/)
endif()