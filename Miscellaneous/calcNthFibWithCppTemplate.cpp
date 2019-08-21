
template<int N>
class Fib {
public:
    enum : unsigned long long {
        value = Fib<N - 1>::value + Fib<N - 2>::value
    };
};

template<>
class Fib<1> {
public:
    enum : unsigned long long {
        value = 1
    };
};

template<>
class Fib<2> {
public:
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