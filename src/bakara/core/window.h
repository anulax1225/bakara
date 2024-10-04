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
        Default window is Initialized with a width of 1000 and a height 800
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

            /*! \fn Bk::Window::GetWidth
            @return The width of the window
            */
            virtual uint GetWidth() const = 0;
            /*! \fn Bk::Window::GetHeight
            @return The height of the window
            */
            virtual uint GetHeight() const = 0;
            
            /*! \fn Bk::Window::OnUpdate
            Updates the frame of the window
            */
            virtual void OnUpdate() = 0;
            /*! \fn Bk::Window::SetEventCallback
            Sets the function pointer for events of the window
            @param callback : function called when a new event occures
            */
            virtual void SetEventCallback(const EventCallback callback) = 0;

            /*! \fn Bk::Window::SetVsync
            Sets the window buffer swap interval. Is enabled by default. 
            If set to false the frame rate should be more constant, but more slow. 
            */
            virtual void SetVsync(bool enable) = 0;
            /*! \fn Bk::Window::IsVsync
            Indicates if window is vsync
            @return Vsync flag
            */
            virtual bool IsVsync() const = 0;

            /*! \fn Bk::Window::Close
            Closes the window    
            */
            virtual void Close() = 0;
            /*! \fn Bk::Window::Open
            Opens and Initializes the window
            */
            virtual void Open() = 0;
            /*! \fn Bk::Window::IsOpen
            Indicates if the window is Opened
            @return Open flag
            */
            virtual bool IsOpen() = 0;

            virtual void* GetNativeWindow() = 0;

            /*! \fn Bk::Window::CreateWindow()
            Static function implemented in the api window class to get a window specifique api.
            If no parameter is specified, creates the window with the default settings.
            @param props : Window information
            */
            static Window* CreateWindow(const WindowProps& props = WindowProps());
    };
}