#include <memory>
#include <utility>
#include <string>
#include <bakara.h>

class TestLayer : public Bk::Layer
{
    public:
        TestLayer()
            : Layer("Test") {}

        void on_attach() override
        {
            BK_INFO("Layer {} attached", name);
        }

        void on_detach() override
        {
            BK_INFO("Layer {} detached", name);
        }

        void OnEvent(Bk::Event& e) override
        {
            BK_INFO("Layer {} event", name);
        }

        void OnUpdate() override
        {
            BK_INFO("Layer {} updated", name);
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