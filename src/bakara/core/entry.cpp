#include "bakara.pch"
#include "application.h"

/*! \file entry.cpp
    This file contains the entry point of the program.
*/

/*! \fn std::unique_ptr<Bk::Application> Bk::create_app()
External function implemented client side.
*/
extern std::unique_ptr<Bk::Application> Bk::create_app();

/*! \fn int main(int argc, char** argv)
Entry of the program.
*/
int main(int argc, char** argv) {
    Bk::Log::init("Bakara");
    std::unique_ptr<Bk::Application> app = Bk::create_app();
    app->run();
    return 0;
}