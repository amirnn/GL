#include "GLShader.hpp"

#include <fstream>
#include <iostream>

namespace
{
  template<typename T> using istreambuffitr = std::istreambuf_iterator<T>;
}

GLShader::GLShader(GLShader::FilePath path, GLShader::ShaderType shaderType) : m_shaderType{shaderType}
{
  switch (shaderType)
  {
  case ShaderType::Vertex: m_id = glCreateShader(GL_VERTEX_SHADER);
    break;

  case ShaderType::Fragment: m_id = glCreateShader(GL_FRAGMENT_SHADER);
    break;
  }
  SetSource(ReadStringFromFile(path));
  m_sourc_ptr = m_source.data();
  CompileShader();
}

GLShader::~GLShader()
{
  ReleaseShaderResources();
}

void GLShader::CompileShader() noexcept
{
  glCompileShader(m_id);
  glShaderSource(m_id, 1, &m_sourc_ptr, nullptr);
  // TODO: Check for errors
  m_isCompiled = true;
}

void GLShader::SetSource(String const& src) noexcept
{
  m_source = src;
}

uint GLShader::GetID() const noexcept
{
  return m_id;
}

void GLShader::ReleaseShaderResources() noexcept
{
  glDeleteShader(m_id);
  m_id = 0;
  m_source.clear();
  m_isCompiled = false;
}

auto GLShader::ReadStringFromFile(FilePath const& path) -> String
{
  String src;
  if (exists(path))
  {
    std::ifstream ifile{path};
    if (ifile.is_open())
    {
      src = std::move(String{istreambuffitr<char>(ifile), istreambuffitr<char>()});
    }
    ifile.close();
  } else
  {
    std::cerr << "Path inavlid. " << " Check: " << path.c_str() << std::endl;
  }
  return src;
}



