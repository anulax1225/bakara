#include <iostream>
#include <memory>
#include <utility>
#include <bakara.h>


class Sandbox : public Bk::Application 
{
    public:
        Sandbox() 
        {
            Bk::Vec2 vec(2.0f, 2.0f);
            BK_INFO("My Vec 2 ({0}, {1})", vec.x, vec.y); 
        }

        ~Sandbox() 
        {

        }
};

std::unique_ptr<Bk::Application> Bk::create_app() {
    return std::unique_ptr<Bk::Application>(new Sandbox());
}