cmake_minimum_required(VERSION 3.14)
project(Othello_Torch)

find_package(Torch REQUIRED)
include_directories(jsoncpp)

add_executable(Othello_Torch Othello.cpp TreeNode.cpp TreeNode.h settings.h Game.cpp Game.h)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -openmp")
target_link_libraries(Othello_Torch "${TORCH_LIBRARIES}")
set_property(TARGET Othello_Torch PROPERTY CXX_STANDARD 11)

