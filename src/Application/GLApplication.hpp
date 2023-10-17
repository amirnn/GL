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

class GLApplication final : public Application {
public:
  GLApplication(Pair<uint, uint> size, String title)
      : m_size{size}, m_title{std::move(title)}, m_window{nullptr} {}

  ~GLApplication() final { Terminate(); }

  void Init() override;
  void MainLoop() override;
  void Terminate() override;

  static void error_callback(int error, const char *description) {
    std::cerr << "Error: " << description << std::endl;
  }

  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
      glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
  }

private:
  Pair<uint, uint> m_size;
  UPointerT<GLWindow> m_window{};
  String m_title;
};