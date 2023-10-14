cmake_minimum_required(VERSION 3.26.5)
project(GL LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Install folder
set(GG_LOCATION ${CMAKE_SOURCE_DIR}/lib/glad)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/build)

# To build and install module
set(SHOULD_BUILD OFF)
set(SHOULD_BUILD_EIGEN OFF)
set(SHOULD_BUILD_GLFW OFF)

add_subdirectory(modules)

add_executable(
    GLApp 
    src/GLApp.cpp
    src/Window/Window.cpp
)

find_library(glfw_lib glfw3 ${CMAKE_SOURCE_DIR}/lib/lib)

target_include_directories(
    GLApp PUBLIC
    lib/include
    lib/glad/include
    src/include
)

target_link_libraries(
    GLApp PUBLIC
    ${glfw_lib}
    ${glad_lib}
)