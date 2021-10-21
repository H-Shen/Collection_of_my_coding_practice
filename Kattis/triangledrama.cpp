// https://open.kattis.com/problems/triangledrama

#include <bits/extc++.h>

using namespace std;
using ll = long long;

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

constexpr int MAXN = 1000005;
struct Node {
    int a,b,c;
    int i,j,k;
    Node() = default;
};

int n;
vector<vector<int>> am;
Node res[MAXN];

int main() {
    IO::read(n);
    am.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            IO::read(am[i][j]);
        }
    }
    int maxVal = -1;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                maxVal = max(maxVal, am[i][j] * am[i][k] * am[j][k]);
            }
        }
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if ((i != j && i != k && j != k) && am[i][j] * am[i][k] * am[j][k] == maxVal) {
                    res[index].a = am[i][j];
                    res[index].b = am[i][k];
                    res[index].c = am[j][k];
                    res[index].i = i;
                    res[index].j = j;
                    res[index].k = k;
                    ++index;
                }
            }
        }
    }
    Node minVal = *min_element(res, res + index, [](const Node&l, const Node&r){
       if (l.a == r.a) {
           if (l.b == r.b) {
               return l.c < r.c;
           }
           return l.b < r.b;
       }
       return l.a < r.a;
    });
    vector<int> ans;
    ans.emplace_back(minVal.i+1);
    ans.emplace_back(minVal.j+1);
    ans.emplace_back(minVal.k+1);
    sort(ans.begin(),ans.end());
    for (auto &i : ans) {
        IO::write(i);
        putchar_unlocked(' ');
    }
    return 0;
}
