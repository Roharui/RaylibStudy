cmake_minimum_required(VERSION 3.2)
project(raylib-study)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

add_definitions("-Wall -std=c++17")

include_directories("${CMAKE_SOURCE_DIR}/include")
# link_directories("${CMAKE_SOURCE_DIR}/lib")

# Change path from /src if needed, or add more directories
file(GLOB_RECURSE sources
        "${CMAKE_SOURCE_DIR}/src/*.c"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )
add_executable(raylib-study ${sources})

target_link_libraries(raylib-study raylib)
