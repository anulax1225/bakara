#include <memory>
#include <utility>
#include <string>
#include <bakara.h>

class TestLayer : public Bk::Layer
{
    public:
        TestLayer()
            : Layer("Test") {}
        void imgui_render() override
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
            push_layer(new TestLayer());
        }
};



std::unique_ptr<Bk::Application> Bk::create_app() {
    return std::unique_ptr<Bk::Application>(new Sandbox());
}