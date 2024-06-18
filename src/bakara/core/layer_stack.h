#pragma once

#include <bakarapch.h>
#include "layer.h"

namespace Bk {
	class LayerStack
	{
		public:
			LayerStack() = default;
			~LayerStack();

			void push_overlay(Layer* layer);
			void pop_overlay(Layer* layer);
			void push_layer(Layer* layer);
			void pop_layer(Layer* layer);
			void clear();

			std::vector<Layer*>::iterator begin() { return p_layers.begin(); }
			std::vector<Layer*>::iterator end() { return p_layers.end(); }

			std::vector<Layer*>::reverse_iterator rbegin() { return p_layers.rbegin(); }
			std::vector<Layer*>::reverse_iterator rend() { return p_layers.rend(); }

		private:
			std::vector<Layer*> p_layers;
			uint p_layer_index = 0;	
	};
}