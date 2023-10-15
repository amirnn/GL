# SRC

add_executable(
        GLApp
        GLApp.cpp
        Window/Window.cpp
)

find_library(glfw_lib glfw3 ${CMAKE_SOURCE_DIR}/build/lib/lib)

target_include_directories(
        GLApp PUBLIC
        ${CMAKE_SOURCE_DIR}/build/lib/include
        ${CMAKE_SOURCE_DIR}/build/lib/glad/include
        include
)

target_link_libraries(
        GLApp PUBLIC
        ${glfw_lib}
        ${glad_lib}
)