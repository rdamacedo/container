cmake_minimum_required(VERSION 2.8)
project(containers)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Profile" CACHE STRING "Build type" FORCE)
    message(STATUS "set build type to ${CMAKE_BUILD_TYPE}")
endif ()


set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
        STRINGS "Debug;Release;RelWithDebInfo;MinSizeRel;Profile")

set(CMAKE_CXX_STANDARD 11)


option(TESTING "Enable testing" ON)
option(FORMAT "Enable formatting" ON)
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
        -std=c++0x
	${CMAKE_CXX_FLAGS}
        -Weffc++
        -Wno-sign-compare
        -Wall
        -Wextra
        -Wshadow
        -Wpointer-arith
        -Wmissing-declarations
        -Wno-unused-parameter
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


if(FORMAT)
    set(astyle_exe ${CMAKE_BINARY_DIR}/astyle/src/bin/astyle)
    add_custom_command(OUTPUT ${astyle_exe}
            COMMAND wget http://sourceforge.net/projects/astyle/files/astyle/astyle%202.05.1/astyle_2.05.1_linux.tar.gz -O /tmp/astyle.tar.gz
            COMMAND tar -xvf /tmp/astyle.tar.gz
            COMMAND cd astyle/src && make -f ../build/gcc/Makefile
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            )

    add_custom_target(check_format
            COMMAND scripts/format.sh ${astyle_exe} 0
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            DEPENDS ${astyle_exe}
            VERBATIM
            )

    add_custom_target(format
            COMMAND scripts/format.sh ${astyle_exe} 1
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            VERBATIM
            DEPENDS ${astyle_exe}
            )
endif()

add_executable(containers ${SOURCE_FILES})
