#include <memory>
#include <utility>
#include <string>
#include <bakara.h>

#include <bakara/events/events.h>

//USE THE FUCKING NAMESPACE OR BREAK

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
            push_layer(new TestLayer());
            std::unique_ptr<Bk::Layer> layer = pop_overlay();
            BK_INFO("Layer retirer et récupérer {0}", layer->to_string());

        }

        ~Sandbox() 
        {

        }
};



std::unique_ptr<Bk::Application> Bk::create_app() {
    return std::unique_ptr<Bk::Application>(new Sandbox());
}