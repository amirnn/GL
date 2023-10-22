#pragma once

#include "Window.hpp"
#include <cassert>

#define GLFW_INCLUDE_NONE
#include "glad/gl.h"
#include <GLFW/glfw3.h>

class GLWindow final : public Window
{

  public:
  GLWindow(uint width, uint height, String &title, bool is_root = true,
           GLFWwindow *wind_ptr = nullptr);

  //  ~GLWindow() override = default;
  ~GLWindow() override;

  GLFWwindow *GetPointer();

  [[nodiscard]] bool ShouldClose() const override;

  [[nodiscard]] bool ShouldContinue() const override;

  std::function<void(GLFWwindow *)> WindowResourceDestroyer =
      [](GLFWwindow *ptr)
      {
        if (ptr)
        {
          glfwDestroyWindow(ptr);
        }
      };
  using GLFWWindowPtr =
      UPointerTD<GLFWwindow, decltype(WindowResourceDestroyer)>;

  private:
  GLFWWindowPtr m_window{};
  //  GLFWwindow *m_window_ptr{};
};