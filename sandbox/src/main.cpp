#include <iostream>
#include <bakara.h>

int main() {
    Bk::Log::Init();
    BK_INFO("Bienvenue dans la sandbox {0}", "bakara");
    Bk::Math::Vec2 vec(2.0f,2.0f);
    std::cout << vec.x << " " << vec.y <<"\n";
}