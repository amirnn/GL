#pragma once

#include "Types/Types.hpp"
#include <filesystem>

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

class GLShader
{
  public:
  using FilePath = std::filesystem::path;

  enum class ShaderType : char
  {
    Vertex = 0,
    Fragment = 1
  };

  GLShader(FilePath path, ShaderType shaderType);
  ~GLShader();

  void SetSource(String const& src) noexcept;

  void CompileShader() noexcept;

  void ReleaseShaderResources() noexcept;

  [[nodiscard]] uint GetID() const noexcept;

  [[nodiscard]] static auto ReadStringFromFile(FilePath const& path) -> String;

  private:
  ShaderType m_shaderType{};
  uint m_id;
  bool m_isCompiled{};
  String m_source{};
  char const *m_sourc_ptr;
};