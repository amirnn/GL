#include "GLApplication.hpp"

void GLApplication::Init() {

  /* Initialize the library */
  if (glfwInit() == GLFW_FALSE) {
    throw std::runtime_error{"GLFW was not initialized."};
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  if (gladLoadGL(glfwGetProcAddress) == 0) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    throw std::runtime_error{"GLAD Loader Failed"};
  }
}

void GLApplication::MainLoop() {

  /* Loop until the user closes the window */
  while (not m_window->ShouldClose()) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(m_window->GetPointer());

    /* Poll for and process events */
    glfwPollEvents();
  }
}

void GLApplication::Terminate() { glfwTerminate(); }