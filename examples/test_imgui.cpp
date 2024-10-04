#include <memory>
#include <utility>
#include <string>
#include <bakara.h>

class TestLayer : public Bk::Layer
{
    public:
        TestLayer()
            : Layer("Test") {}
        void ImguiRender() override
        {
            static bool show = true;
            ImGui::ShowDemoWindow(&show);
        }

};

class Sandbox : public Bk::Application 
{
    public:
        Sandbox() 
        { 
            PushLayer(new TestLayer());
        }
};



std::unique_ptr<Bk::Application> Bk::CreateApp() {
    return std::unique_ptr<Bk::Application>(new Sandbox());
}