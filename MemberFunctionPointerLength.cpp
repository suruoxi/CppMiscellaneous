// For more information. See
// http://www.cnblogs.com/hazir/p/wide-pointers.html
/*
	主要是考虑到多重继承
*/
#include <iostream>
#include <string.h>
using namespace std;
struct A {
    void foo() const {
        std::cout << "A's this:\t" << this << std::endl;
    }
    char pad0[32];
};

struct B {
    void bar() const {
        std::cout << "B's this:\t" << this << std::endl;
    }
    char pad2[64];
};

struct C : A, B
{ };

void call_by_ptr(const C &obj, void (C::*mem_func)() const)
{
    void *data[2];
    memcpy(data, &mem_func, sizeof(mem_func));
    std::cout << "------------------------------\n"
        "Object ptr:\t" << &obj <<
        "\nFunction ptr:\t" << data[0] <<
        "\nPointer adj:\t" << data[1] << std::endl;
    (obj.*mem_func)();
}

int main()
{
    C obj;
    call_by_ptr(obj, &C::foo);
    call_by_ptr(obj, &C::bar);
}
