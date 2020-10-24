// https://open.kattis.com/problems/keepitcool
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

struct Node {
    int slot_id;
    int current_bottles;
};

int main() {

    int n, m, s, d;
    IO::read(n, m, s, d);
    vector<Node> A(s);
    for (int i = 0; i < s; ++i) {
        A.at(i).slot_id = i;
        IO::read(A.at(i).current_bottles);
    }
    auto A_copy(A);
    sort(A.begin(), A.end(), [](const Node &l, const Node &r) {
        if (l.current_bottles == r.current_bottles) {
            return (l.slot_id < r.slot_id);
        }
        return (l.current_bottles < r.current_bottles);
    });
    vector<int> need_to_fill(s);
    int fill_bottles;
    for (const auto &i : A) {
        fill_bottles = min(n, d - i.current_bottles);
        need_to_fill.at(i.slot_id) = fill_bottles;
        n -= fill_bottles;
        if (n <= 0) {
            break;
        }
    }
    int available_cold_soda = 0;
    for (int i = 0; i < s; ++i) {
        if (need_to_fill.at(i) == 0) {
            available_cold_soda += A_copy.at(i).current_bottles;
        }
    }
    if (available_cold_soda < m) {
        puts("impossible");
        return 0;
    }

    // output
    IO::write(need_to_fill.at(0));
    for (int i = 1; i < s; ++i) {
        putchar_unlocked(' ');
        IO::write(need_to_fill.at(i));
    }
    putchar_unlocked('\n');
    return 0;
}
