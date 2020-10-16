// https://open.kattis.com/problems/bank
//
#include <bits/stdc++.h>

using namespace std;
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

constexpr int MAXN = 10005;

struct Node {
    ll c, t;
};

int n, t;
bitset<MAXN> vis;

int main() {

    IO::read(n, t);
    vector<Node> A(n);
    for (auto &i : A) {
        IO::read(i.c, i.t);
    }
    ll cash_in_best_choice ;
    int index_of_best_choice;
    ll answer = 0;

    for (int current_due = min(t, n); current_due >= 0; current_due--) {
        cash_in_best_choice = 0;
        index_of_best_choice = -1;
        // Start checking
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && A.at(j).c > cash_in_best_choice && A.at(j).t >= current_due) {
                cash_in_best_choice = A.at(j).c;
                index_of_best_choice = j;
            }
        }
        if (index_of_best_choice != -1) {
            answer += cash_in_best_choice;
            vis[index_of_best_choice] = true;
        }
    }
    IO::writeln(answer);

    return 0;
}
