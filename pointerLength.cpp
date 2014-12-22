#include <iostream>

int main() {
    std::cout <<
        "sizeof(int*)      == " << sizeof(int*) << "\n"
        "sizeof(double*)   == " << sizeof(double*) << "\n"
        "sizeof(void(*)()) == " << sizeof(void(*)()) << std::endl;
}