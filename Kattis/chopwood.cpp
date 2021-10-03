// https://open.kattis.com/problems/chopwood

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

vector<pair<int,int>> prufer_decode(const vector<int>& prufer_code, bool& exist) {
    vector<pair<int,int>> edgeList;
    int n = (int)prufer_code.size() + 1;
    if (prufer_code[n-2] != n) {
        exist = false;
        return edgeList;
    }
    vector<int> degree(n, 1);
    for (auto &i : prufer_code) {
        ++degree[i];
    }
    priority_queue<int, vector<int>, greater<>> leaves;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            leaves.push(i);
        }
    }
    for (auto &v : prufer_code) {
        int u = leaves.top();
        leaves.pop();
        edgeList.emplace_back(u, v);
        --degree[v];
        if (degree[v] == 1) {
            leaves.push(v);
        }
    }
    return edgeList;
}

int n;
vector<int> code;

int main() {
    IO::read(n);
    code.resize(n);
    for (auto &i : code) {
        IO::read(i);
    }
    bool exist = true;
    auto res = prufer_decode(code, exist);
    if (!exist) {
        puts("Error");
        return 0;
    }
    for (const auto &[u,v] : res) {
        IO::writeln(u);
    }

    return 0;
}
