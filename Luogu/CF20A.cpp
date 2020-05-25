#include <bits/extc++.h>

using namespace std;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

constexpr int MAXN = 105;
char s[MAXN];

int main(int argc, char *argv[]) {

    scanf("%s", s);
    string output;
    for (int i = 0; s[i] != 0; ++i) {
        if (i > 0 && s[i] == '/' && s[i - 1] == '/') {
            continue;
        } else {
            output.push_back(s[i]);
        }
    }
    if (output.size() > 1 && output.back() == '/') {
        output.pop_back();
    }
    printf("%s\n", output.c_str());

    return 0;
}