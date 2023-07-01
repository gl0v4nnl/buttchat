cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

# Set application properties
set(PROJECT_NAME buttchat)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} main.cpp qna.cpp)
