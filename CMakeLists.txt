cmake_minimum_required(VERSION 3.22)
project(LinearAlgebraLib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# Build the shared library (.so)
add_library(LinearAlgebraLib SHARED
        ${CMAKE_SOURCE_DIR}/src/Vector3D.cpp
        ${CMAKE_SOURCE_DIR}/src//Matrix.cpp
)

# Include directories (public API)
target_include_directories(LinearAlgebraLib PUBLIC
        ${CMAKE_SOURCE_DIR}/include/
        ${CMAKE_SOURCE_DIR}/include/LinearAlgebraLib/
)

find_package(GTest REQUIRED)

# Visibility settings (Linux/macOS optimization)
target_compile_options(LinearAlgebraLib PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-fvisibility=hidden>
)

# Optional installation instructions
install(TARGETS LinearAlgebraLib
        EXPORT LinearAlgebraLibConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)

install(DIRECTORY include/LinearAlgebraLib DESTINATION include)

# Include testing support
enable_testing()
add_subdirectory(tests)