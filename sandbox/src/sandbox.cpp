#include <iostream>
#include <memory>
#include <utility>
#include <bakara.h>

class Sandbox : public Bk::Application 
{
    public:
        Sandbox() 
        {
            auto event = Bk::WindowResizeEvent(120, 120);
            auto key_event = Bk::KeyPressEvent(Bk::Key::A);
            auto mouse_event = Bk::MouseMoveEvent(2.3f, 1.2f);
            std::cout << event.to_string() << "\n" << key_event.to_string() << "\n" << mouse_event.get_pos().x << "\n";
            BK_CORE_IMP_ASSERT(false, "Big Error")
        }

        ~Sandbox() 
        {

        }
};

std::unique_ptr<Bk::Application> Bk::create_app() {
    return std::unique_ptr<Bk::Application>(new Sandbox());
}