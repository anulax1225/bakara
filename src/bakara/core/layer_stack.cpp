#include "layer_stack.h"

namespace Bk {
	LayerStack::~LayerStack() { clear(); }

	void LayerStack::push_overlay(Layer* layer)
	{
		layer->on_attach();
		p_layers.emplace_back(layer);
	}

	void LayerStack::pop_overlay(Layer* layer)
	{
		auto it = std::find(p_layers.begin() + p_layer_index, p_layers.end(), layer);
		if (it != p_layers.end())
		{
			layer->on_detach();
			p_layers.erase(it);
		}
	}

	void LayerStack::push_layer(Layer* layer)
	{
		layer->on_attach();
		p_layers.emplace(p_layers.begin() + p_layer_index, layer);
		p_layer_index++;
	}

	void LayerStack::pop_layer(Layer* layer)
	{
		auto it = std::find(p_layers.begin(), p_layers.begin() + p_layer_index, layer);
		if (it != p_layers.begin() + p_layer_index)
		{
			layer->on_detach();
			p_layers.erase(it);
			p_layer_index--;
		}
	}

	void LayerStack::clear()
	{
		std::for_each(p_layers.begin(), p_layers.end(), [](Layer* layer)
			{
				layer->on_detach();
				delete layer;
			});
		p_layers.clear();
		p_layer_index = 0;
	}
}