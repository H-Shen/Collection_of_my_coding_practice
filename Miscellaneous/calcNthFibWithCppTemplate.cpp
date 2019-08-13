#include <bits/stdc++.h>

using namespace std;

template<int N>
struct Fib {
    enum : unsigned long long {
        value = Fib<N - 1>::value + Fib<N - 2>::value
    };
};

template<>
struct Fib<1> {
    enum : unsigned long long {
        value = 1
    };
};

template<>
struct Fib<2> {
    enum : unsigned long long {
        value = 1
    };
};

int main() {
    static_assert(Fib<1>::value == 1UL, "");
    static_assert(Fib<2>::value == 1UL, "");
    static_assert(Fib<93>::value == 12200160415121876738UL, "");
    return 0;
}