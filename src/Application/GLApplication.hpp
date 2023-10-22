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
#include "Shader/GLShaderProgram.hpp"
#include "Shader/GLShader.hpp"

class GLApplication final : public Application
{
  public:
  GLApplication(Pair<uint, uint> size, String title);

  ~GLApplication() final;

  /**
   * @brief Called in the constructor
   */
  void Init() override;
  void MainLoop() override;
  /**
   * @brief Called in the destructor
   */
  void Terminate() override;

  static void error_callback(int error, const char *description);

  static void key_callback(GLFWwindow *window, int key, int scancode,
                           int action, int mods);

  private:
  Pair<uint, uint> m_size;
  Vector<Positionf> m_verticies;
  UPointerT<GLShader> m_vertexShader{};
  UPointerT<GLShader> m_fragmentShader{};
  UPointerT<GLShaderProgram> m_shaderProgram{};
  UPointerT<GLWindow> m_window{};
  String m_title;
};