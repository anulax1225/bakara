#pragma once

#include <imgui.h>
#include "bakara/core/layer.h"

namespace Bk {
	class ImguiLayer : public Layer 
	{
		public:
	        ImguiLayer()
	            : Layer("Imgui") {}

	        void on_attach() override;
	        void on_detach() override;
	        void begin();
	        void end();
	};
}