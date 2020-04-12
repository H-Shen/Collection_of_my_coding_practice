#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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
    puts("");
}

int main() {

    string str;
    char ch;
    while (true) {
        scanf("%c", &ch);
        if (ch == '@') {
            break;
        }
        str.push_back(ch);
    }
    int n = static_cast<int>(str.size());
    int left = 0;
    for (int i = 0; i < n; ++i) {
        if (str.at(i) == '(') {
            ++left;
        } else if (str.at(i) == ')') {
            --left;
        }
        if (left < 0) {
            printf("NO\n");
            return 0;
        }
    }
    if (left == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}