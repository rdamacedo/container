cmake_minimum_required(VERSION 3.7)
project(containers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
                    utils/Utils.cpp utils/Utils.h
                    container/Container.cpp
                    container/Container.h
                    hashtable/Entry.h
                    hashtable/HashTable.h
                    hashtable/HashKey.h)
add_executable(containers ${SOURCE_FILES})