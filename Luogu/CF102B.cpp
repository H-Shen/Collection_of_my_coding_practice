#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

constexpr int MAXN = 100005;
char s[MAXN];

int main() {

    scanf("%s", s);
    string str(s);
    if (str.size() == 1) {
        printf("0\n");
        return 0;
    }
    int counter = 1;
    int sum = 0;
    for (const char &ch : str) {
        sum += (int) (ch - '0');
    }
    while (sum >= 10) {
        int temp = 0;
        str = to_string(sum);
        for (const char &ch : str) {
            temp += (int) (ch - '0');
        }
        sum = temp;
        ++counter;
    }
    IO::writeln(counter);

    return 0;
}