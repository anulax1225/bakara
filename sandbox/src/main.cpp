#include <iostream>
#include <bakara/test.h>
#include <bakara/math/vec.h>

int main() {
    std::cout << Bk::Math::add(2,2) << "\n";
    Bk::Math::Vec2 vec(2.0f,2.0f);
    std::cout << vec.x << " " << vec.y <<"\n";
}