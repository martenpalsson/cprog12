cmake_minimum_required(VERSION 2.8)

FILE(GLOB cpp_files src/*.cpp)

add_definitions(-Wall --std=c++0x)

add_executable(game ${cpp_files})
target_link_libraries(game boost_regex)
