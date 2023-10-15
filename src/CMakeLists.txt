# SRC

find_package(glfw3 3.3 PATHS ${CMAKE_SOURCE_DIR}/build/lib/lib/cmake/glfw3 REQUIRED)
find_package(Eigen3 PATHS ${CMAKE_SOURCE_DIR}/build/lib/share/eigen3/cmake REQUIRED)

add_executable(
        main
        ${CMAKE_SOURCE_DIR}/build/lib/glad/src/gl.c
        Window/Window.cpp
        Window/GLWindow.cpp
        Application/Application.cpp
        Application/GLApplication.cpp
        main.cpp
)

target_include_directories(
        main PUBLIC
        ${CMAKE_SOURCE_DIR}/build/lib/include
        ${CMAKE_SOURCE_DIR}/build/lib/glad/include
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/include
)

target_link_libraries(
        main PUBLIC
        glfw
        Eigen3::Eigen
        ${glad_lib}
)