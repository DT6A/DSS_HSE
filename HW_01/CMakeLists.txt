cmake_minimum_required(VERSION 3.15)
project(HW_01)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(../smhasher/src)
include_directories(../xxHash)

add_compile_options(
        "$<$<CONFIG:DEBUG>:-O3;-g3;-ggdb>"
)


add_executable(HW_01
        include/csv_writer.hpp
        include/measure_utils.hpp
        include/smhasher_helper_header.hpp
        src/csv_writer.cpp
        src/main.cpp
        src/measure_utils.cpp
        ../smhasher/src/SpeedTest.cpp
        ../smhasher/src/MurmurHash3.cpp
        ../smhasher/src/Hashes.cpp
        ../xxHash/xxhash.c
        )
