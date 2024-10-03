#pragma once 

/*! \file window.h
This file contiens all the interfaces to create a window.
Implementation possible with GLFW, Win32, etc.
*/

#include "bakara.pch"
#include <bakara/events/event.h>

namespace Bk {

    /* \struct Bk::WindowProps
    Structure containing the essential data to create a window.
    */
    struct WindowProps 
    {
        std::string title; //!< Title at the top of the window
        uint width; //!< Width of the window
        uint height; //!< Height of the window

        /*! \fn Bk::WindowProps::WindowProps
        Default window is initialized with a width of 1000 and a height 800
        @param title : Title of the window
        @param width : Width of the window
        @param height : Height of the window
        */
        WindowProps(std::string title = "Bakara engine", uint width = 1000, uint height = 800)
            : title(title), width(width), height(height) {}
    };

    /*! \class Bk::Window
    Window is an interface to abstract witch window api is used. This enable compilation with multiple api, 
    so that it's possible to use the native api of the platform or to implement a graphics api's with more ease.   
    */
    class Window 
    {
        public: 
            /*! \typedef Bk::Window::EventCallback
            The EventCallback is a function pointer that takes a Event as parameter 
            and that reponses to them. 
            */
            using EventCallback = std::function<void(Event& e)>;

            /*! \fn Bk::Window::~Window
            Virtual destructor enables subclasses to cleanup on termination.
            */
            virtual ~Window() {}

            /*! \fn Bk::Window::get_width
            @return The width of the window
            */
            virtual uint get_width() const = 0;
            /*! \fn Bk::Window::get_height
            @return The height of the window
            */
            virtual uint get_height() const = 0;
            
            /*! \fn Bk::Window::on_update
            Updates the frame of the window
            */
            virtual void on_update() = 0;
            /*! \fn Bk::Window::set_event_callback
            Sets the function pointer for events of the window
            @param callback : function called when a new event occures
            */
            virtual void set_event_callback(const EventCallback callback) = 0;

            /*! \fn Bk::Window::set_vsync
            Sets the window buffer swap interval. Is enabled by default. 
            If set to false the frame rate should be more constant, but more slow. 
            */
            virtual void set_vsync(bool enable) = 0;
            /*! \fn Bk::Window::is_vsync
            Indicates if window is vsync
            @return Vsync flag
            */
            virtual bool is_vsync() const = 0;

            /*! \fn Bk::Window::close
            Closes the window    
            */
            virtual void close() = 0;
            /*! \fn Bk::Window::open
            Opens and initializes the window
            */
            virtual void open() = 0;
            /*! \fn Bk::Window::is_open
            Indicates if the window is opened
            @return Open flag
            */
            virtual bool is_open() = 0;

            virtual void* get_native_window() = 0;

            /*! \fn Bk::Window::create_window()
            Static function implemented in the api window class to get a window specifique api.
            If no parameter is specified, creates the window with the default settings.
            @param props : Window information
            */
            static Window* create_window(const WindowProps& props = WindowProps());
    };
}