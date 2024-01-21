#include <iostream>
#include <memory>
#include <utility>
#include <bakara.h>


class Sandbox : public Bk::Application 
{
    public:
        Sandbox() 
        {
            
        }

        ~Sandbox() 
        {

        }
};

std::unique_ptr<Bk::Application> Bk::create_app() {
    return std::unique_ptr<Bk::Application>(new Sandbox());
}