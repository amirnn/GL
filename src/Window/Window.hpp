#pragma once

#include <exception>
#include <functional>
#include <memory>
#include <stdexcept>
#include <utility>

#include "Types.hpp"

class Window
{
  public:
  Window(uint width, uint height, String &title, bool is_root);

  virtual ~Window() = default;

  [[nodiscard]] virtual bool ShouldClose() const = 0;

  [[nodiscard]] virtual bool ShouldContinue() const;

  [[nodiscard]] Pair<uint, uint> GetSize() const;

  void SetSize(Pair<uint, uint> const &size);

  [[nodiscard]] String GetTitle() const;

  [[nodiscard]] bool IsRoot() const;

  protected:
  uint m_width;
  uint m_height;
  String m_title;
  bool m_is_root{};
};