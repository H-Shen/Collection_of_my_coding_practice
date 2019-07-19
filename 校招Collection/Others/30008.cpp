#include <iostream>
#include <cassert>
using namespace std;
class Sample{
public:
    int v;
    Sample(int n):v(n) { }
    Sample(const Sample &A) { v = 10; }
};
int main() {
    Sample a(5);
    Sample b = a;
    assert(b.v == 10);
    return 0;
}