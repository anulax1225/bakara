#include "layer_stack.h"

namespace Bk {
	LayerStack::~LayerStack()
	{
		std::for_each(p_layers.begin(), p_layers.end(), [](Layer* layer)
			{
				layer->on_detach();
				delete layer;
			});
		p_layers.clear();
	}

	void LayerStack::push_overlay(Layer* layer)
	{
		layer->on_attach();
		p_layers.emplace_back(layer);
	}

	std::unique_ptr<Layer> LayerStack::pop_overlay()
	{
		if(auto layer = p_layers.back())
		{ 
			p_layers.pop_back();
			return std::make_unique<Layer>(*layer); 
		}
		return nullptr;
	}

	void LayerStack::push_layer(Layer* layer)
	{
		layer->on_attach();
		p_layers.emplace_front(layer);
	}

	std::unique_ptr<Layer> LayerStack::pop_layer()
	{
		if(auto layer = p_layers.front()) 
		{ 
			p_layers.pop_front();
			return std::make_unique<Layer>(*layer); 
		}
		return nullptr;
	}

	void LayerStack::clear()
	{
		p_layers.clear();
	}
}