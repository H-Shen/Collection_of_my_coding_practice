// https://open.kattis.com/problems/soundex
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

namespace IO {
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

unordered_map<char, int> unmap;

void solve(const string &s) {
    int n = (int)s.size();
    char last = 0;
    for (int i = 0; i < n; ++i) {
        if (last == 0) {
            last = s.at(i);
            if (unmap.find(last) != unmap.end()) {
                cout << unmap[last];
            }
        } else {
            if (unmap.find(s.at(i)) == unmap.end()) {
                last = s.at(i);
            } else if (unmap.find(last) == unmap.end() || unmap[last] != unmap[s.at(i)]) {
                last = s.at(i);
                cout << unmap[last];
            }
        }
    }
    cout << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // pre
    unmap['B'] = 1;
    unmap['F'] = 1;
    unmap['P'] = 1;
    unmap['V'] = 1;
    unmap['C'] = 2;
    unmap['G'] = 2;
    unmap['J'] = 2;
    unmap['K'] = 2;
    unmap['Q'] = 2;
    unmap['S'] = 2;
    unmap['X'] = 2;
    unmap['Z'] = 2;
    unmap['D'] = 3;
    unmap['T'] = 3;
    unmap['L'] = 4;
    unmap['M'] = 5;
    unmap['N'] = 5;
    unmap['R'] = 6;

    string s;
    while (cin >> s) {
        solve(s);
    }

    return 0;
}
