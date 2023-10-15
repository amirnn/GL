#pragma once

#include "Window.hpp"

class GLWindow : public Window {

public:
  GLWindow(uint width, uint height, String &title, bool is_root)
      : Window{width, height, title, is_root} {
    /* Initialize the library */
    if (glfwInit() == GLFW_FALSE) {
      throw std::runtime_error{"GLFW was not initialized."};
    }
    m_window.reset(
        glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL));
    if (not m_window) {
      throw std::runtime_error{"Window pointer not valid."};
    }
    if (m_is_root) {
      /* Make the window's context current */
      glfwMakeContextCurrent(m_window.get());
    }
  }

  ~GLWindow() {
    if (m_is_root) {
      glfwTerminate();
    }
  }

  bool ShouldClose() const { return glfwWindowShouldClose(m_window.get());}

private:
  std::function<void(GLFWwindow *)> const WindowResourceDestroyer =
      [](GLFWwindow *ptr) { glfwDestroyWindow(ptr); };
  UPointer<GLFWwindow, decltype(WindowResourceDestroyer)> m_window{};
};