cmake_minimum_required(VERSION 3.12)
project(untitled5)

set(CMAKE_CXX_STANDARD 11)

include_directories(/Users/yangzij/Source/nginx-1.12.0/src/core)
include_directories(/Users/yangzij/Source/nginx-1.12.0/src/os/unix)
include_directories(/Users/yangzij/Source/nginx-1.12.0/objs)


add_executable(untitled5 main.cpp Wrapper.cpp Wrapper.h Pool.cpp Pool.h UnsetValue.cpp UnsetValue.h Value.cpp Value.h Exception.cpp Exception.h Config.h Cleaup.cpp Cleaup.h Alloctor.cpp Alloctor.h)