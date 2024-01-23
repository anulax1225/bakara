#pragma once

#include <bkpch.h>
#include <bakara/io/window.h>
#include <bakara/events/events.h>
#include <bakara/core/layer_stack.h>

namespace Bk {

    #define BK_BIND_EVENT_FN(fn) [this](Event& e) { fn(e); }
    #define BK_BIND_DISPACHER_FN(event, fn) [this](event& e) -> bool{ return fn(e); }

    class Application 
    {
        public:
            Application();
            virtual ~Application();
            void on_event(Event& e);
            bool on_window_close(WindowCloseEvent& e);
            bool on_window_resize(WindowResizeEvent& e);

            void push_overlay(Layer*  layer) { layer_stack.push_overlay(layer); }
            std::unique_ptr<Layer> pop_overlay() { return layer_stack.pop_overlay(); }
            void push_layer(Layer*  layer) { layer_stack.push_layer(layer); }
            std::unique_ptr<Layer> pop_layer() { return layer_stack.pop_layer(); }

            void run();
        private:
            std::unique_ptr<Window> p_window;
            LayerStack layer_stack;
            bool p_running = true;
    };

    std::unique_ptr<Application> create_app();
}