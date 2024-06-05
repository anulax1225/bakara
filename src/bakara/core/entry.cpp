#include <bkpch.h>
#include "log.h"
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
    Bk::Log::init();
    BK_CORE_INFO("Bienvenue dans la sandbox {0} version {1}", "bakara", 1);
    std::unique_ptr<Bk::Application> app = Bk::create_app();
    app->run();
    return 0;
}