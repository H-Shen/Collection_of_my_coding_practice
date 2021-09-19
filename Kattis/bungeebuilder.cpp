// https://open.kattis.com/problems/bungeebuilder

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }

    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
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
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

// Sparse Table
struct ST {
    vector<vector<int> > spt;
    vector<int> Log2;
    int n, logn;
    ST() = default;
    void f() {
        Log2.resize(n + 5);
        Log2.at(1) = 0;
        Log2.at(2) = 1;
        for (int i = 3; i < n + 5; ++i)
            Log2.at(i) = Log2.at(i >> 1) + 1;
        logn = floor(log2(n) + 2);
        spt.resize(n + 5, vector<int>(logn));
    }
    void init() {
        for (int j = 1; j <= logn; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                spt.at(i).at(j) = min(spt.at(i).at(j - 1),
                                      spt.at(i + (1 << (j - 1))).at(j - 1));
            }
        }
    }
    int rangeMin(int l, int r) {
        int s = Log2.at(r - l + 1);
        int ans = min(spt.at(l).at(s), spt.at(r - (1 << s) + 1).at(s));
        return ans;
    }
};

int n;
vector<int> h, v1, v2;
ST st;

// the index of last greater or equal element, -1 means such element does not exist
vector<int> getLastGreaterOrEqual() {
    vector<int> ans(n);
    ans[0] = -1;
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; ++i) {
        while (!s.empty() && h[s.top()] < h[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> getNextGreaterOrEqual() {
    vector<int> ans(n);
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; ++i) {
        if (s.empty()) {
            s.push(i);
            continue;
        }
        while (!s.empty() && h[s.top()] <= h[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty()) {
        ans[s.top()] = -1;
        s.pop();
    }
    return ans;
}

int main() {
    IO::read(n);
    h.resize(n);
    for (auto &i : h) IO::read(i);
    v1 = getLastGreaterOrEqual();
    v2 = getNextGreaterOrEqual();
    st.n = n;
    st.f();
    for (int i = 1; i <= n; ++i) {
        st.spt[i][0] = h[i-1];
    }
    st.init();
    int ans = 0;
    int l, r;
    for (int i = 0; i < n; ++i) {
        if (v1[i] != -1 && v1[i] != i - 1) {
            l = v1[i]+1;
            r = i-1;
            ans = max(ans, min(h[v1[i]], h[i]) - st.rangeMin(l + 1, r + 1));
        }
        if (v2[i] != -1 && v2[i] != i + 1) {
            l = i+1;
            r = v2[i]-1;
            ans = max(ans, min(h[v2[i]], h[i]) - st.rangeMin(l + 1, r + 1));
        }
    }
    IO::writeln(ans);
    return 0;
}
