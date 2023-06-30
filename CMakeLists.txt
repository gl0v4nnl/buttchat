cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

project(buttchat)

# add_library(buttchat main.h qna.h)

add_executable(buttchat main.cpp qna.cpp)