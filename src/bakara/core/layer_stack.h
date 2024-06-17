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
			void pop_overlay();
			void push_layer(Layer* layer);
			void pop_layer();
			void clear();

			std::deque<Layer*>::iterator begin() { return p_layers.begin(); }
			std::deque<Layer*>::iterator end() { return p_layers.end(); }

			std::deque<Layer*>::reverse_iterator rbegin() { return p_layers.rbegin(); }
			std::deque<Layer*>::reverse_iterator rend() { return p_layers.rend(); }

		private:
			std::deque<Layer*> p_layers;
			uint p_layer_index = 0;	
	};
}