#include "application.h"

/*! \file entry.cpp
    This file contains the entry point of the program.
*/

/*! \fn std::unique_ptr<Bk::Application> Bk::CreateApp()
External function implemented client side.
*/
extern Bk::Application* Bk::CreateApp(int argc, char** argv);

/*! \fn int main(int argc, char** argv)
Entry of the program.
*/
int main(int argc, char** argv) {
    Bk::Log::Init("Bakara");
    Bk::Application* app = Bk::CreateApp(argc, argv);
    app->Run();
    delete app;
    return 0;
}