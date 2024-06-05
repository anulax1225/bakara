#include "imgui_layer.h"

namespace Bk {
	void ImguiLayer::on_attach() 
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); 


		Application& app = Application::get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.get_window()->get_native_window());

		// Setup Platform/Renderer bindings
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImguiLayer::on_detach() 
	{

	}

	void ImguiLayer::on_event(Bk::Event& e) 
	{

	}

	void ImguiLayer::on_update()
	{

	}
}