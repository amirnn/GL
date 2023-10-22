#include "GLShaderProgram.hpp"

GLShaderProgram::GLShaderProgram(GLShader vertexSahderProgram, GLShader fragmentShader) :
    m_vertexShader{vertexSahderProgram.GetID()}, m_fragmentShader{fragmentShader.GetID()}
{
  CreateProgram();
}

GLShaderProgram::~GLShaderProgram()
{
  ReleaseProgramResources();
}

void GLShaderProgram::SetVertexShader(uint vshader)
{
  m_vertexShader = vshader;
}

void GLShaderProgram::SetFragmentShader(uint fshader)
{
  m_fragmentShader = fshader;
}

void GLShaderProgram::CreateProgram()
{
  m_id = glCreateProgram();
  glAttachShader(m_id, m_vertexShader);
  glAttachShader(m_id, m_fragmentShader);
  glLinkProgram(m_id);
  m_isCompiled = true;
}

uint GLShaderProgram::GetID() const noexcept
{
  return m_id;
}

void GLShaderProgram::ReleaseProgramResources()
{
  glDeleteProgram(m_id);
  m_id = 0;
  m_isCompiled = false;
}