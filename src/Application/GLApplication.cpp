#include "GLApplication.hpp"

void GLApplication::Init() {

  /* Initialize the library */
  if (glfwInit() == GLFW_FALSE) {
    throw std::runtime_error{"GLFW was not initialized."};
  }
  glfwSetErrorCallback(error_callback);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
#if defined(__APPLE__)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
#else
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
#endif
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if defined(__APPLE__)
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void GLApplication::MainLoop() {

  /* Loop until the user closes the window */
  while (not m_window->ShouldClose()) {
    /* Render here */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(m_window->GetPointer());

    /* Poll for and process events */
    glfwPollEvents();
  }
}

void GLApplication::Terminate() {
  m_window.reset();
  glfwTerminate();
}