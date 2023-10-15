cmake_minimum_required(VERSION 3.26.4)
project(GL LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Install folder
#set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/lib)

# To build and install module
set(SHOULD_BUILD_DEPS OFF)
set(SHOULD_BUILD_EIGEN OFF)
set(SHOULD_BUILD_GLFW OFF)

# Turn off the generation of the test targets
set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

# Out put dir for glad
set(GLAD_OUT_DIR ${CMAKE_SOURCE_DIR}/build/lib/glad)

add_subdirectory(modules)

if (NOT SHOULD_BUILD_DEPS)
    add_subdirectory(src)
endif ()
