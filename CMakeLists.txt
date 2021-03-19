cmake_minimum_required(VERSION 3.9)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Library locations (Change these to the appropriate path on your machine)
# set(INCLUDE_DIR C:/DevelopmentLibraries/include/)
# set(LIB_DIR C:/DevelopmentLibraries/lib/x64)

# Tell CMake where to look for include and libs
# include_directories(${INCLUDE_DIR})
# link_directories(${LIB_DIR})

# Create a project
project(EmscriptenLibTest)

file(GLOB_RECURSE SIMPLE_LIBRARY_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
add_executable(SimpleLibrary ${SIMPLE_LIBRARY_SRCS})
# target_link_libraries(SimpleWindow SDL2)
# target_link_libraries(SimpleWindow SDL2main)