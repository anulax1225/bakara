#include <iostream>
#include <bakara/test.h>
#include <bakara.h>

int main() {
    std::cout << Bk::Math::add(2,2) << "\n";
    Bk::Math::vec2 vec(2,2);
    std::cout << vec.x << " " << vec.y <<"\n";
}