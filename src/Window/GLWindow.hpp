#pragma once

#include "Window.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "glad/gl.h"


class GLWindow : public Window {

public:
  GLWindow(uint width, uint height, String &title, bool is_root)
      : Window{width, height, title, is_root} {
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

  ~GLWindow() override = default;

  GLFWwindow * GetPointer(){
    return m_window.get();
  }

  bool ShouldClose() const override { return glfwWindowShouldClose(m_window.get());}

private:
  std::function<void(GLFWwindow *)> const WindowResourceDestroyer =
      [](GLFWwindow *ptr) { glfwDestroyWindow(ptr); };
  UPointerTD<GLFWwindow, decltype(WindowResourceDestroyer)> m_window{};
};