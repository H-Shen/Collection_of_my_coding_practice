#include <string>
#include <iostream>

using namespace std;

// __int128 is defined in MacOS/GNUC and Linux/GNUC
#if defined(__GNUC__) && (defined(__APPLE__) || defined(__linux__))

string printInt128(__int128 a) { // prints as decimal
    if (!a) {
        return "0";
    }
    string s;
    while (a) {
        s = char(llabs(static_cast<long long>(a % 10)) + '0') + s;
        if (-10 < a && a < 0) {
            s = '-' + s;
        }
        a /= 10;
    }
    return s;
}

__int128 parseInt128(const string &s) { // parses decimal number
    __int128 a = 0, sgn = 1;
    for (char c : s) {
        if (c == '-') sgn *= -1; else a = a * 10 + sgn * (c - '0');
    }
    return a;
}

void test() {
    __int128 a(parseInt128("70141183460469231731687303715884105727"));
    __int128 b(parseInt128("70141183460469231731687303715884105728"));
    __int128 c(parseInt128("-70141183460469231731687303715884105727"));
    cout << printInt128(a + b) << endl;
    cout << printInt128(a + c) << endl;
}

#endif

int main() {

#if defined(__GNUC__) && (defined(__APPLE__) || defined(__linux__))
    test();
#endif

    return 0;
}