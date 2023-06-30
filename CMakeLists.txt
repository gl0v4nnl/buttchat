cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

# Set application properties
set(PROJECT_NAME single_thread_echo_server)

project(${PROJECT_NAME})

set(Boost_INCLUDE_DIR home/ivan/Projects/boost)
find_package( Boost 1.82 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )

add_executable(${PROJECT_NAME} main.cpp qna.cpp)

target_link_libraries( ${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES} )
