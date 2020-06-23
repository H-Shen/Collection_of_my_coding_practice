#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

// OEIS: A002854
std::integer_sequence<int,
        1, 1, 2, 3, 7, 16, 54, 243, 2038, 33120, 1182004, 87723296, 907260828,
        445874017, 131059413, 750854059, 85710140, 46269468, 106575268,
        569924828, 477980796, 853121491, 916490672, 848722293, 179336057,
        577163661, 709912061, 916083428, 988859367, 286999618, 29547862,
        713350279, 194424628, 553076032, 609634772, 876525030, 182311698,
        148716617, 346128108, 650982654, 373128192, 361260409, 524419271,
        834718796, 514750301, 478609700, 386216865, 881562716, 715225681,
        602577017, 758593079, 957974751, 163267530, 655824093, 427187849,
        785749570, 905949862, 284908253, 328047464, 987684422> p;

template<typename T, T... elements>
constexpr T get(integer_sequence<T, elements...>, size_t i) {
    constexpr T temp_array[] = {elements...};
    return temp_array[i];
}

int main() {
    int n;
    IO::read(n);
    IO::writeln(get(p, n - 1));
    return 0;
}