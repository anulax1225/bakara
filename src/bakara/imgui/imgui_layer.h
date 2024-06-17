#pragma once

#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
#include <bakara/core/application.h>
#include <bakara/core/layer.h>

namespace Bk {
	class ImguiLayer : public Layer 
	{
		public:
	        ImguiLayer()
	            : Layer("Imgui") {}

	        void on_attach() override;
	        void on_detach() override;
	        void on_event(Bk::Event& e) override;
	        void on_update() override;
	};
}