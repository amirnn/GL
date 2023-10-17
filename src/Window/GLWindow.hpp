#pragma once

#include "Window.hpp"
#include <assert.h>

#define GLFW_INCLUDE_NONE
#include "glad/gl.h"
#include <GLFW/glfw3.h>

class GLWindow : public Window {

public:
  GLWindow(uint width, uint height, String &title, bool is_root,
           GLFWwindow *wind_ptr = nullptr)
      : Window{width, height, title, is_root}, m_window{wind_ptr} {
    if (not wind_ptr) {
      m_window.reset(glfwCreateWindow(m_width, m_height, m_title.c_str(),
                                      nullptr, nullptr));
    }
    if (not m_window) {
      throw std::runtime_error{"Window pointer not valid."};
    }
  }

  //  ~GLWindow() override = default;
  ~GLWindow() override {
    if (m_window) {
      m_window.reset();
    }
  }

  GLFWwindow *GetPointer() { return m_window.get(); }

  [[nodiscard]] bool ShouldClose() const override {
    return glfwWindowShouldClose(m_window.get());
  }

  [[nodiscard]] bool ShouldContinue() const {
    return not glfwWindowShouldClose(m_window.get());
  }

  std::function<void(GLFWwindow *)> WindowResourceDestroyer{
      [&](GLFWwindow *ptr) {
        if (ptr) {
          glfwDestroyWindow(ptr);
        }
      }};
  using GLFWWindowPtr =
      UPointerTD<GLFWwindow, decltype(WindowResourceDestroyer)>;

private:
  GLFWWindowPtr m_window{};
  //  GLFWwindow *m_window_ptr{};
};