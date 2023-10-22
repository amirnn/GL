//
// Created by Amir Nourinia on 22.10.23.
//

#pragma once

#include "Types.hpp"

#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#include <concepts>

template<typename T>
concept SizeAware =
requires(T t) { t.size(); };

template<typename T>
concept GraphicsDataConcept = SizeAware<T> && std::movable<T> && std::copyable<T>;

template<typename T>
requires GraphicsDataConcept<T>
class GBuffer
{
  public:
  enum class BufferType : char
  {
    ArrayBuffer = 0,
  };

  GBuffer(BufferType type, uint drawType, UPointerT<T> dataPtr) :
      m_type{type}, m_drawType{drawType}
  {
    m_oglType = GetOglType(type);
    SetData(dataPtr);
  }

  void Bind()
  {
    uint type{};
    glBindBuffer(type, m_id);
  }

  void SetData(UPointerT<T> ptr)
  {
    m_dataPtr.reset(ptr);
    glGenBuffers(1, &m_id);
    glBindBuffer(m_oglType, m_id);
    glBufferData(m_oglType, m_dataSize, m_dataPtr, m_drawType);
  }

  void SetAttributes()
  {
    glVertexAttribPointer(0, m_id->size(), GL_FLOAT, GL_FALSE, 3 * sizeof(float),
                          (void *) 0);
    glEnableVertexAttribArray(0);
  }

  void ReleaseData()
  {
    m_dataPtr.reset();
  }

  private:
  uint m_id;

  BufferType m_type;

  uint m_oglType;

  uint m_drawType{};

  size_t m_dataSize{};

  UPointerT<T> m_dataPtr{};

  [[nodiscard]] static uint GetOglType(BufferType type) noexcept
  {
    switch (type)
    {
    case BufferType::ArrayBuffer: return GL_ARRAY_BUFFER;
    default:return 0u;
    }
  }
};

