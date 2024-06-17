#include "layer_stack.h"

namespace Bk {
	LayerStack::~LayerStack()
	{
		clear();
	}

	void LayerStack::push_overlay(Layer* layer)
	{
		layer->on_attach();
		p_layers.emplace_back(layer);
	}

	void LayerStack::pop_overlay()
	{
		if(auto layer = p_layers.back())
		{ 
			layer->on_detach();
			p_layers.pop_back();
			delete layer;
		}
	}

	void LayerStack::push_layer(Layer* layer)
	{
		layer->on_attach();
		p_layers.emplace_front(layer);
	}

	void LayerStack::pop_layer()
	{
		if(auto layer = p_layers.front()) 
		{ 
			layer->on_detach();
			p_layers.pop_front();
			delete layer;
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
	}
}