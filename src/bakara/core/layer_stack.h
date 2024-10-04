#pragma once

#include "bakara.pch"
#include "layer.h"

namespace Bk {
	class LayerStack
	{
		public:
			LayerStack() = default;
			~LayerStack();

			void PushOverlay(Layer* layer);
			void PopOverlay(Layer* layer);
			void PushLayer(Layer* layer);
			void PopLayer(Layer* layer);
			void clear();

			std::vector<Layer*>::iterator begin() { return p_layers.begin(); }
			std::vector<Layer*>::iterator end() { return p_layers.end(); }
			std::vector<Layer*>::iterator Begin() { return p_layers.begin(); }
			std::vector<Layer*>::iterator End() { return p_layers.end(); }

			std::vector<Layer*>::reverse_iterator ReverseBegin() { return p_layers.rbegin(); }
			std::vector<Layer*>::reverse_iterator ReverseEnd() { return p_layers.rend(); }

		private:
			std::vector<Layer*> p_layers;
			uint p_layer_index = 0;	
	};
}