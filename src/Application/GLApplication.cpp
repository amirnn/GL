#include "GLApplication.hpp"

GLApplication::GLApplication(Pair<uint, uint> size, String title)
    : m_size{size}, m_title{std::move(title)}, m_window{nullptr}
{
  /**
   * @brief Since we are in a final class
   * it is acceptable to call a virtual function
   * at its constructor
   */
  Init();
}

GLApplication::~GLApplication()
{ Terminate(); }

void GLApplication::Init()
{
  /* Initialize the library */
  if (glfwInit() == GLFW_FALSE)
  {
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

  m_window =
      std::make_unique<GLWindow>(m_size.first, m_size.second, m_title);
  if (m_window->IsRoot())
  {
    /* Make the window's context current */
    glfwMakeContextCurrent(m_window.get()->GetPointer());
  }
  if (gladLoadGL(glfwGetProcAddress) == 0)
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    throw std::runtime_error{"GLAD Loader Failed"};
  }
  // Set callbacks
  glfwSetKeyCallback(m_window->GetPointer(), key_callback);
}

void GLApplication::MainLoop()
{

  /* Loop until the user closes the window */
  while (m_window->ShouldContinue())
  {
    /* Render here */
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(m_window->GetPointer());

    /* Poll for and process events */
    glfwPollEvents();
  }
}

void GLApplication::Terminate()
{
  m_window.reset();
  glfwTerminate();
}
void GLApplication::error_callback(int error, char const *description)
{
  std::cerr << "Error: " << description << std::endl;
}
void GLApplication::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, GLFW_TRUE);
  }
}



