#pragma once

#include <exception>
#include <functional>
#include <memory>
#include <stdexcept>
#include <utility>

#include "Types.hpp"

class Window {
public:
  Window(uint width, uint height, String &title, bool is_root)
      : m_width{width}, m_height{height}, m_title{title}, m_is_root{is_root} {}

  virtual ~Window() = default;

  [[nodiscard]] virtual bool ShouldClose() const = 0;
  [[nodiscard]] Pair<uint, uint> GetSize() const { return {m_width, m_height}; }

  void SetSize(Pair<uint, uint> const &size) {
    m_width = size.first;
    m_height = size.second;
  }

  [[nodiscard]] String GetTitle() const { return m_title; }

  [[nodiscard]] bool IsRoot() const { return m_is_root; }

protected:
  uint m_width;
  uint m_height;
  String m_title;
  bool m_is_root{};
};