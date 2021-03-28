cmake_minimum_required(VERSION 3.9)

# In case of linux, tell it to places binaries in bin folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Library locations (Change these to the appropriate path on your machine)
set(INCLUDE_DIR C:/DevelopmentLibraries/include/)
set(LIB_DIR C:/DevelopmentLibraries/lib/x64)

# Tell CMake where to look for include and libs
include_directories(${INCLUDE_DIR})
link_directories(${LIB_DIR})

# Create a project
project(EmscriptenTest)

# Set emscripten specific compiler and linker flags
if (EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX .html)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -s WASM=1")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -s FORCE_FILESYSTEM=1")
    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']")
endif()

# Create executable for FileRead
file(GLOB_RECURSE FILE_READ_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} examples/FileRead/src/*.cpp)
add_executable(FileRead ${FILE_READ_SRC})

# Create simple math library for use with the factorial application
add_library(SimpleMath STATIC examples/MathLibrary/src/SimpleMath.h examples/MathLibrary/src/SimpleMath.cpp)
add_executable(Factorial examples/MathLibrary/src/main.cpp)
target_link_libraries(Factorial SimpleMath)
