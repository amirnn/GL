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

#include "Window/GLWindow.hpp"
#include "Application.hpp"
#include "Types.hpp"

class GLApplication: public Application{
    public:
    GLApplication(Pair<uint, uint> size, String const& title):
    m_size{size},
    m_title{title}
    {   
        // Inits GLFW
        Init();
        m_window.reset( new GLWindow{m_size.first, m_size.second, m_title, true});
    }

    void Init() override;
    void MainLoop() override;
    void Terminate() override;

    private:
    Pair<uint, uint> m_size;
    UPointerT<GLWindow> m_window{};
    String m_title;

};