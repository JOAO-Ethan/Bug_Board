cmake_minimum_required(VERSION 3.24)
project(JOAO_Ethan_CA3)

set(CMAKE_CXX_STANDARD 17)

add_executable(JOAO_Ethan_CA3 main.cpp Bug.cpp Bug.h Crawler.cpp Crawler.h Hopper.cpp Hopper.h Board.cpp Board.h BishopBug.cpp BishopBug.h SuperBug.cpp SuperBug.h)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(/usr/include)
target_link_libraries(JOAO_Ethan_CA3 sfml-system sfml-window sfml-graphics sfml-audio)