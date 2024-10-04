#include "bakara.pch"
#include "application.h"

/*! \file entry.cpp
    This file contains the entry point of the program.
*/

/*! \fn std::unique_ptr<Bk::Application> Bk::CreateApp()
External function implemented client side.
*/
extern std::unique_ptr<Bk::Application> Bk::CreateApp();

/*! \fn int main(int argc, char** argv)
Entry of the program.
*/
int main(int argc, char** argv) {
    Bk::Log::Init("Bakara");
    std::unique_ptr<Bk::Application> app = Bk::CreateApp();
    app->Run();
    return 0;
}