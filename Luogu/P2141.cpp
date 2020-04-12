#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// Usage: int a, b, c; read<int>(a, b, c);
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
// Usage: int a = 1231; writeln(a);
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

    int n, val;
    read<int>(n);
    unordered_set<int> unset;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        read<int>(val);
        unset.insert(val);
        A.at(i) = val;
    }
    unordered_set<int> output;
    int temp;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            temp = A.at(i) + A.at(j);
            if (unset.find(temp) != unset.end()) {
                output.insert(temp);
            }
        }
    }
    writeln<long>(output.size());

    return 0;
}
