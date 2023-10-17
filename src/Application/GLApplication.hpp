#pragma once

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>

// GLAD
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

// GLFW (include after glad)
#include <GLFW/glfw3.h>

#include "Application.hpp"
#include "Types.hpp"
#include "Window/GLWindow.hpp"

class GLApplication : public Application {
public:
  GLApplication(Pair<uint, uint> size, String const &title)
      : m_size{size}, m_title{title}, m_window{nullptr} {
    // Inits GLFW
    Init();
    m_window.reset(new GLWindow{m_size.first, m_size.second, m_title, true});
    if (m_window->IsRoot()) {
      /* Make the window's context current */
      glfwMakeContextCurrent(m_window.get()->GetPointer());
    }
    if (gladLoadGL(glfwGetProcAddress) == 0) {
      std::cout << "Failed to initialize GLAD" << std::endl;
      throw std::runtime_error{"GLAD Loader Failed"};
    }
    // Set callbacks
    glfwSetKeyCallback(m_window->GetPointer(), key_callback);

  }

  void Init() override;
  void MainLoop() override;
  void Terminate() override;

  static void error_callback(int error, const char *description) {
    std::cerr << "Error: " << description << std::endl;
  }

  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GLFW_TRUE);
  }

private:
  Pair<uint, uint> m_size;
  UPointerT<GLWindow> m_window{};
  String m_title;
};