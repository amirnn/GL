#include "Window.hpp"

Pair<uint, uint> Window::GetSize() const
{ return {m_width, m_height}; }

Window::Window(uint width, uint height, String &title, bool is_root)
    : m_width{width}, m_height{height}, m_title{title}, m_is_root{is_root}
{}

void Window::SetSize(Pair<uint, uint> const &size)
{
  m_width = size.first;
  m_height = size.second;
}

String Window::GetTitle() const
{ return m_title; }

bool Window::IsRoot() const
{ return m_is_root; }

bool Window::ShouldContinue() const
{
  return not ShouldClose();
}
