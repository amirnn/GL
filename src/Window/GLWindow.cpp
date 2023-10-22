#include "GLWindow.hpp"

GLWindow::GLWindow(uint width, uint height, String &title, bool is_root,
                   GLFWwindow *wind_ptr)
    : Window{width, height, title, is_root}, m_window{wind_ptr}
{
  if (not wind_ptr)
  {
    m_window = std::unique_ptr<GLFWwindow, decltype(WindowResourceDestroyer)>(
        glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr),
        WindowResourceDestroyer
    );
  }
  if (not m_window)
  {
    throw std::runtime_error{"Window pointer not valid."};
  }
}

GLWindow::~GLWindow()
{
  if (m_window)
  {
    m_window.reset(nullptr);
  }
}

GLFWwindow *GLWindow::GetPointer()
{ return m_window.get(); }

bool GLWindow::ShouldClose() const
{
  return glfwWindowShouldClose(m_window.get());
}

bool GLWindow::ShouldContinue() const
{
  return not glfwWindowShouldClose(m_window.get());
}
