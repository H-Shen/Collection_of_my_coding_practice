#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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
        puts("");
    }
}


int main() {

    int n;
    IO::read(n);
    vector<int> A(n);
    for (auto &i : A) {
        IO::read(i);
    }
    if (n == 1) {
        printf("Not jolly\n");
        return 0;
    }
    vector<int> temp_vec(n - 1);
    iota(temp_vec.begin(), temp_vec.end(), 1);
    unordered_set<int> temp_unset(temp_vec.begin(), temp_vec.end());
    for (int i = 1; i < n; ++i) {
        temp_unset.erase(abs(A.at(i) - A.at(i - 1)));
    }
    if (temp_unset.empty()) {
        printf("Jolly\n");
    } else {
        printf("Not jolly\n");
    }

    return 0;
}
