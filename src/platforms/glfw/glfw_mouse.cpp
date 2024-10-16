#include "bakara/io/mouse.h"
#include "bakara/core/application.h"
#include <GLFW/glfw3.h>

namespace Bk 
{
  Vec2 Mouse::GetPosition()
  {
    auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    return { (float)xpos, (float)ypos };
  }

  bool Mouse::ButtonUp(Code button)
  {
    auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
    return state == GLFW_RELEASE;
  }

  bool Mouse::ButtonDown(Code button)
  {
    auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
    return state == GLFW_PRESS;
  }

  bool Mouse::ButtonRepeat(Code button)
  {
    auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
    auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));
    return state == GLFW_REPEAT;
  }
}