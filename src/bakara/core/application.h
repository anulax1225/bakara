#pragma once

/*! \file application.h
This file contains the main app abstraction.
*/

#include <bakarapch.h>
#include <bakara/core/window.h>
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
            */
            inline void pop_overlay(Layer*  layer) { p_layer_stack.pop_overlay(layer); }
            /*! \fn Bk::Application::push_overlay
            Push's the layer at the bottom of the layer stack
            @param layer : Layer pointer to push
            */
            inline void push_layer(Layer*  layer) { p_layer_stack.push_layer(layer); }
            /*! \fn Bk::Application::push_overlay
            Pop's the layer at the bottom of the layer stack
            */
            inline void pop_layer(Layer*  layer) { p_layer_stack.pop_layer(layer); }

            /*! \fn Bk::Application::run
            Starts the application and the update loop.
            */
            void run();

            std::shared_ptr<Window> get_window() { return std::shared_ptr<Window>(h_window); }

            static Application& get() { return *p_instance; }

        protected:
            std::shared_ptr<Window> h_window; //!< Pointer to the main window

            /*! \fn Bk::Application::close
            Stops the application and the update loop without creating an event.
            */
            void close();

        private:
            LayerStack p_layer_stack; //!< Layer stack of the application
            bool p_running; //!< Flag that indicates if the update loop should stop or not 
            static Application* p_instance;
    };
    /*! \fn std::unique_ptr<Application> Bk::create_app()
    Is used to retrive the user app class instance, made from inheritance.
    Must be defined in the user program
    @return User defined application
    */
    std::unique_ptr<Application> create_app();
}