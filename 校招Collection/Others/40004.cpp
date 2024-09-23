#include <bits/stdc++.h>

using namespace std;

class MyInt {
    int nVal;
public:
    MyInt(int n) { nVal = n; }

    int ReturnVal() { return nVal; }

    MyInt &operator-(int a) {
        nVal -= a;
        return *this;
    }
};

int main() {
    MyInt objInt(10);
    objInt - 2 - 1 - 3;
    assert(objInt.ReturnVal() == 4);
    objInt - 2 - 1;
    assert(objInt.ReturnVal() == 1);
    return 0;
}