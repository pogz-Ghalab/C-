cmake_minimum_required(VERSION 2.8.4)

project(client) 

message(STATUS "start running cmake...")
add_executable(client src/client.cpp)
TARGET_LINK_LIBRARIES(client pthread)

set_property(TARGET client PROPERTY CXX_STANDARD 11)