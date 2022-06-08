set(CMAKE_GENERATOR, "mingw32-make")
cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
project (glimpse)
file(GLOB SOURCES src/*.cpp)
add_subdirectory()
add_executable(glimpse ${SOURCES})
target_include_directories(glimpse
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src/include
        ${PROJECT_SOURCE_DIR}/src/include/SDL2-2.0.22/i686-w64-mingw32/include/SDL2
)