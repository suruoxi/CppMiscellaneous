// For more information. See
// http://www.cnblogs.com/hazir/p/wide-pointers.html

#include <iostream>

struct Foo {
    void bar() const { }
};

int main() {
    std::cout << sizeof(&Foo::bar) << std::endl;
}