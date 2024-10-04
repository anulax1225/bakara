#pragma once

#include <imgui.h>
#include "bakara/core/layer.h"

namespace Bk {
	class ImguiLayer : public Layer 
	{
		public:
	        ImguiLayer()
	            : Layer("Imgui") {}

	        void OnAttach() override;
	        void OnDetach() override;
	        void Begin();
	        void End();
	};
}