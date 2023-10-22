#pragma once

#include "Types.hpp"
#include "Shader/GLShader.hpp"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

class GLShaderProgram
{
  public:

  GLShaderProgram(GLShader vertexSahderProgram, GLShader fragmentShader);

  ~GLShaderProgram();

  void SetVertexShader(uint vshader);

  void SetFragmentShader(uint fshader);

  void CreateProgram();

  [[nodiscard]] uint GetID() const noexcept;

  void ReleaseProgramResources();

  private:
  uint m_id{};
  uint m_vertexShader{};
  uint m_fragmentShader{};
  bool m_isCompiled{};
};