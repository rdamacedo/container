cmake_minimum_required(VERSION 3.7)
project(containers)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Profile" CACHE STRING "Build type" FORCE)
    message(STATUS "set build type to ${CMAKE_BUILD_TYPE}")
endif ()


set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
        STRINGS "Debug;Release;RelWithDebInfo;MinSizeRel;Profile")

set(CMAKE_CXX_STANDARD 11)


option(TESTING "Enable testing" ON)
option(COV_HTML "Display html for coverage" ON)


set(SOURCE_FILES main.cpp
        utils/Utils.cpp utils/Utils.h
        container/Container.cpp
        container/Container.h
        hashtable/Entry.h
        hashtable/HashTable.h
        hashtable/HashKey.h)

set(CMAKE_CXX_FLAGS_PROFILE
        ${CMAKE_CXX_FLAGS_DEBUG}
        --coverage
        -fno-inline
        -fno-inline-small-functions
        -fno-default-inline
        )

string(REPLACE ";" " " CMAKE_CXX_FLAGS_PROFILE "${CMAKE_CXX_FLAGS_PROFILE}")

set(CMAKE_CXX_FLAGS
        ${CMAKE_CXX_FLAGS}
        -Weffc++
        -Wno-sign-compare
        -Wall
        -Wextra
        -Wshadow
        -Wpointer-arith
        -Wmissing-declarations
        -Wno-unused-parameter
        -Werror=format-security
        -Werror=array-bounds
        -Werror=unused-variable
        -Werror=uninitialized
        -Werror=init-self
        -Wcast-qual
        -Wconversion
        -Wcast-align
        )

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

file(GLOB_RECURSE COV_SRCS "tests/*")

if (TESTING)
    enable_testing()
    add_subdirectory(tests)
endif ()

add_executable(containers ${SOURCE_FILES})
