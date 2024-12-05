set(SOURCE_FILES
    srcs/vector2.cpp
    srcs/vector3.cpp
    srcs/matrix3.cpp
    srcs/transform.cpp
    srcs/tests/tests.cpp
)

# PROJECT
cmake_minimum_required(VERSION 3.10)
project(maths VERSION 1.0)

# COMPILATION AND FLAGS
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

add_executable(maths ${SOURCE_FILES})
target_include_directories(maths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
