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

        void on_event(Bk::Event& e) override
        {
            BK_INFO("Layer {} event", name);
        }

        void on_update() override
        {
            BK_INFO("Layer {} updated", name);
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