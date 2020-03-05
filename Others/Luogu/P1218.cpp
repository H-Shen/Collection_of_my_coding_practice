#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int c = getchar();
        t = 0;
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

int main() {

    vector<int> A = {2, 3, 5, 7, 23, 29, 31, 37, 53, 59, 71, 73, 79, 233, 239,
                     293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797,
                     2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793,
                     3797, 5939, 7193, 7331, 7333, 7393, 23333, 23339, 23399,
                     23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393,
                     59399, 71933, 73331, 73939, 233993, 239933, 293999, 373379,
                     373393, 593933, 593993, 719333, 739391, 739393, 739397,
                     739399, 2339933, 2399333, 2939999, 3733799, 5939333,
                     7393913, 7393931, 7393933, 23399339, 29399999, 37337999,
                     59393339, 73939133};

    size_t n;
    scanf("%zd", &n);
    for (const int &i : A) {
        if (to_string(i).size() == n) {
            printf("%d\n", i);
        }
    }
    return 0;
}
