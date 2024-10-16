#include "bakara/io/keyboard.h"
#include "bakara/core/application.h"
#include <GLFW/glfw3.h>

namespace Bk 
{
    bool Keyboard::KeyDown(Code key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_PRESS;
	}

    bool Keyboard::KeyUp(Code key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_RELEASE;
	}

    bool Keyboard::KeyRepeat(Code key)
	{
		auto* window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, static_cast<int32_t>(key));
		return state == GLFW_REPEAT;
	}
}