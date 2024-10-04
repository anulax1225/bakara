#pragma once

/*! \file application.h
This file contains the main app abstraction.
*/

#include "bakara.pch"
#include "bakara/core/window.h"
#include "bakara/events/events.h"
#include "bakara/io/mouse.h"
#include "bakara/io/keyboard.h"
#include "bakara/core/layer_stack.h"
#include "bakara/imgui/imgui_layer.h"

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

            /*! \fn Bk::Application::OnEvent
            Function bound to the window to get all event from it
            @param e : Event to be processed 
            */
            void OnEvent(Event& e);

            /*! \fn Bk::Application::OnWindowClose 
            Handler of Bk::WindowCloseEvent and will be bind to a event dispacher
            @param e : event to handled
            */
            virtual bool OnWindowClose(WindowCloseEvent& e);
            /*! \fn Bk::Application::OnWindowResize  
            Handler of Bk::WindowResizeEvent and will be bind to a event dispacher
            @param e : event to handled
            */
            virtual bool OnWindowResize(WindowResizeEvent& e);

            /*! \fn Bk::Application::PushOverlay
            Push's the layer on top of the layer stack
            @param layer : Layer pointer to push
            */
            inline void PushOverlay(Layer*  layer) { p_layer_stack.PushOverlay(layer); }
            /*! \fn Bk::Application::PopOverlay
            Pop's the layer on top of the layer stack
            */
            inline void PopOverlay(Layer*  layer) { p_layer_stack.PopOverlay(layer); }
            /*! \fn Bk::Application::PushOverlay
            Push's the layer at the bottom of the layer stack
            @param layer : Layer pointer to push
            */
            inline void PushLayer(Layer*  layer) { p_layer_stack.PushLayer(layer); }
            /*! \fn Bk::Application::PushOverlay
            Pop's the layer at the bottom of the layer stack
            */
            inline void PopLayer(Layer*  layer) { p_layer_stack.PopLayer(layer); }

            /*! \fn Bk::Application::run
            Starts the application and the update loop.
            */
            void Run();

            Window& GetWindow() { return *h_window; }

            static Application& Get() { return *p_instance; }

        protected:
            std::unique_ptr<Window> h_window; //!< Pointer to the main window
            ImguiLayer* imgui_layer; 

            /*! \fn Bk::Application::Close
            Stops the application and the update loop without creating an event.
            */
            void Close();

        private:
            LayerStack p_layer_stack; //!< Layer stack of the application
            bool p_running; //!< Flag that indicates if the update loop should stop or not 
            static Application* p_instance;
    };
    /*! \fn std::unique_ptr<Application> Bk::CreateApp()
    Is used to retrive the user app class instance, made from inheritance.
    Must be defined in the user program
    @return User defined application
    */
    std::unique_ptr<Application> CreateApp();
}