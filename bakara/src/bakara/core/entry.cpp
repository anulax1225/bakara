#include <bkpch.h>
#include "log.h"
#include "application.h"


extern std::unique_ptr<Bk::Application> Bk::create_app();

int main(int argc, char** argv) {
    Bk::Log::init();
    BK_CORE_INFO("Bienvenue dans la sandbox {0} version {1}", "bakara", 1);
    std::unique_ptr<Bk::Application> app = Bk::create_app();
    app->run();
    return 0;
}