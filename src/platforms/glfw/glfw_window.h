#pragma once

#include "bakara/core/deltatime.h"
#include "bakara/core/window.h"
#include "platforms/opengl/opengl_context.h"

struct GLFWwindow;

namespace Bk::Platform {
    struct GlfwWindowData 
    {
        std::string title;
        uint width;
        uint height;
        bool vsync;
        EventCallback callback;
        GraphicsContext* context;
        ~GlfwWindowData();
    };

    class GlfwWindow : public Window
    {
        public:
            GlfwWindow(const WindowProps& props);
            virtual ~GlfwWindow();

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

            virtual DeltaTime GetTime() override { return dt; } 
        private:
            bool h_IsOpen; //!< indicaste if the window is Opened or not
            bool p_Shutdown;

            GLFWwindow* p_window;
            GlfwWindowData p_data;

            float lastFrameTime = 0.0f;
            DeltaTime dt = { 0.0f };
            
            void InitEventCallbacks();
            void Init();
            void Shutdown();
    };
}