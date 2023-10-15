#pragma once

#include <exception>
#include <functional>
#include <memory>
#include <stdexcept>
#include <utility>

#include <GLFW/glfw3.h>

#include "Types.hpp"

class Window {

public:
  Window(uint width, uint height, String &title, bool is_root)
      : m_width{width}, m_height{height}, m_title{title}, m_is_root{is_root} {
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

  ~Window(){
    if (m_is_root) {
        glfwTerminate();
    }
  }

  bool ShouldClose() const {
    return glfwWindowShouldClose(m_window.get());
  }

  Pair<uint, uint> GetSize() const {
    return {m_width, m_height};
  }

  void SetSize(Pair<uint, uint> const & size) {
    m_width = size.first;
    m_height = size.second;
  }

  String GetTitle() const {
    return m_title;
  }

  bool IsRoot() const {
    return m_is_root;
  }



private:
  uint m_width;
  uint m_height;
  String m_title;
  bool m_is_root{};

  std::function<void(GLFWwindow *)> const WindowResourceDestroyer =
      [](GLFWwindow *ptr) { glfwDestroyWindow(ptr); };
  UPointer<GLFWwindow, decltype(WindowResourceDestroyer)> m_window{};
};