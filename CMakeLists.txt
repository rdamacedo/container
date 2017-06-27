cmake_minimum_required(VERSION 3.7)
project(containers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hashtable/Hashtable.cpp hashtable/Hashtable.h utils/Utils.cpp utils/Utils.h container/Container.cpp container/Container.h)
add_executable(containers ${SOURCE_FILES})