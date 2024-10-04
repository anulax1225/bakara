#include "layer_stack.h"

namespace Bk {
	LayerStack::~LayerStack() { clear(); }

	void LayerStack::PushOverlay(Layer* layer)
	{
		layer->OnAttach();
		p_layers.emplace_back(layer);
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		auto it = std::find(p_layers.begin() + p_layer_index, p_layers.end(), layer);
		if (it != p_layers.end())
		{
			layer->OnDetach();
			p_layers.erase(it);
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		layer->OnAttach();
		p_layers.emplace(p_layers.begin() + p_layer_index, layer);
		p_layer_index++;
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(p_layers.begin(), p_layers.begin() + p_layer_index, layer);
		if (it != p_layers.begin() + p_layer_index)
		{
			layer->OnDetach();
			p_layers.erase(it);
			p_layer_index--;
		}
	}

	void LayerStack::clear()
	{
		std::for_each(p_layers.begin(), p_layers.end(), [](Layer* layer)
			{
				layer->OnDetach();
				delete layer;
			});
		p_layers.clear();
		p_layer_index = 0;
	}
}