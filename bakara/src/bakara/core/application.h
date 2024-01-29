#pragma once

/*! \file application.h
This file contains the main app abstraction.
*/

#include <bkpch.h>
#include <bakara/io/window.h>
#include <bakara/events/events.h>
#include <bakara/core/layer_stack.h>

namespace Bk {
    /*! \class Bk::Application
    Serves as the entry for the users program.
    This handles layers, the main window, and events. It makes sure to propegate events and updates through the layers.
    */
    class Application 
    {
        public:
            /*! \fn Bk::Application
            Initializes the main window and binds the event callback
            */
            Application();
            /*! \fn Bk::Application::~Application
            Virtual destructor enables subclasses to cleanup on termination
            */
            virtual ~Application();

            /*! \fn Bk::Application::on_event
            Function bound to the window to get all event from it
            @param e : Event to be processed 
            */
            void on_event(Event& e);

            /*! \fn Bk::Application::on_window_close 
            Handler of Bk::WindowCloseEvent and will be bind to a event dispacher
            @param e : event to handled
            */
            virtual bool on_window_close(WindowCloseEvent& e);
            /*! \fn Bk::Application::on_window_resize  
            Handler of Bk::WindowResizeEvent and will be bind to a event dispacher
            @param e : event to handled
            */
            virtual bool on_window_resize(WindowResizeEvent& e);

            /*! \fn Bk::Application::push_overlay
            Push's the layer on top of the layer stack
            @param layer : Layer pointer to push
            */
            inline void push_overlay(Layer*  layer) { p_layer_stack.push_overlay(layer); }
            /*! \fn Bk::Application::pop_overlay
            Pop's the layer on top of the layer stack
            @return a unique ptr to the layer ressource
            */
            inline std::unique_ptr<Layer> pop_overlay() { return p_layer_stack.pop_overlay(); }
            /*! \fn Bk::Application::push_overlay
            Push's the layer at the bottom of the layer stack
            @param layer : Layer pointer to push
            */
            inline void push_layer(Layer*  layer) { p_layer_stack.push_layer(layer); }
            /*! \fn Bk::Application::push_overlay
            Pop's the layer at the bottom of the layer stack
            @return a unique ptr to the layer ressource
            */
            inline std::unique_ptr<Layer> pop_layer() { return p_layer_stack.pop_layer(); }

            /*! \fn Bk::Application::run
            Starts the application and the update loop.
            */
            void run();

        protected:
            std::unique_ptr<Window> h_window; //!< Pointer to the main window

        private:
            LayerStack p_layer_stack; //!< Layer stack of the application
            bool p_running = true; //!< Flag that indicates if the update loop should stop or not 
    };
    /*! \fn std::unique_ptr<Application> Bk::create_app()
    Is used to retrive the user app class instance, made from inheritance.
    Must be defined in the user program
    @return User defined application
    */
    std::unique_ptr<Application> create_app();
}