#include <iostream>
#include <cassert>

using namespace std;

class A {
    int val;
public:
    A(int n) { val = n; }

    int GetVal() { return val; }
};

class B : public A {
private:
    int val;
public:
    B(int n) :
            A(n + 4), val(n + 2) {}

    int GetVal() { return val; }
};

int main() {

    B b1(2);
    assert(b1.GetVal() == 4);
    assert(b1.A::GetVal() == 6);

    return 0;
}