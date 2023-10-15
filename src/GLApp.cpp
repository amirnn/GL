#include <cstdlib>
#include <iostream>
#include <memory>

// GLAD
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>

// GLFW (include after glad)
#include <GLFW/glfw3.h>

#include "Window/Window.hpp"
#include "Application/Application.hpp"

class GLApp: public Application{
    public:
    GLApp(Pair<uint, uint> size, String const& title):
    m_size{size},
    m_title{title},
    m_window{size.first, size.second,m_title,true}
    {}

    void Init() override {}
    void MainLoop() override {}
    void Terminate() override {}

    private:
    Pair<uint, uint> m_size;
    Window m_window;
    String m_title;

};

int main(){
    GLApp glapp{{640, 480},"Hello There"};
    glapp.Run();
    return  EXIT_SUCCESS;
}