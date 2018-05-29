cmake_minimum_required(VERSION 3.9)
project(Screw-Your-Neighbor)

set(CMAKE_CXX_STANDARD 11)

add_executable(Screw-Your-Neighbor main.cpp src/Card.cpp include/Card.h src/Deck.cpp include/Deck.h include/Player.h src/Player.cpp include/Game.h src/Game.cpp)