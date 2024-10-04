#pragma once
#include "bakara.pch"
#include "bakara/core/window.h"
#include "bakara/events/events.h"
#include "platforms/opengl/opengl_context.h"

struct GLFWwindow;

namespace Bk::Platform {
    class WinGLFW : public Window
    {
        public:
            WinGLFW(const WindowProps& props);
            virtual ~WinGLFW();

            inline uint GetWidth() const override { return p_data.width; }
            inline uint GetHeight() const override { return p_data.height; }
        
            void OnUpdate() override;
            void SetEventCallback(const EventCallback callback) override;

            void SetVsync(bool enable) override;
            bool IsVsync() const override;

            void Close() override;
            void Open() override;

            void* GetNativeWindow() override { return p_window; }
            /*! \fn Bk::Window::IsOpen
            Indicates if the window is Opened
            @return Open flag
            */
            bool IsOpen() override { return h_IsOpen; }
        private:
            bool h_IsOpen; //!< indicaste if the window is Opened or not
            bool p_Shutdown;

            GLFWwindow* p_window;
            OpenglContext* context;
            struct WindowData 
            {
                std::string title;
                uint width;
                uint height;
                bool vsync;
                EventCallback callback;
            };
            WindowData p_data;
            
            void InitEventCallbacks();
            void Init();
            void Shutdown();
    };
}