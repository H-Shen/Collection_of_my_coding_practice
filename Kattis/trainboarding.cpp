// https://open.kattis.com/problems/trainboarding

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using int128 = __int128;
using pii = pair<int, int>;

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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    int n, l, p;
    IO::read(n, l, p);
    vector<int> train;
    for (int i = 0; i < n; ++i) {
        train.emplace_back(l*(2*i+1)/2);
    }

    vector<int> A(p);
    for (auto &i : A) IO::read(i);
    vector<int> unmap(n, 0);
    ll longestPath = 0;
    for (const auto &i : A) {
        if (i <= l/2) {
            ++unmap[0];
            longestPath = max((ll)(l/2-i), longestPath);
        }
        else if (i >= l*(2*(n-1)+1)/2) {
            ++unmap[n-1];
            longestPath = max((ll)(i-l*(2*(n-1)+1)/2), longestPath);
        }
        else {
            int index = (int)(lower_bound(train.begin(), train.end(), i)-train.begin());
            int index2 = index - 1;
            int dist2 = abs(i-l*(2*index2+1)/2);
            int dist1 = abs(i-l*(2*index+1)/2);
            if (dist1 <= dist2) {
                ++unmap[index];
                longestPath = max((ll)dist1, longestPath);
            }
            else if (dist1 > dist2) {
                ++unmap[index2];
                longestPath = max((ll)dist2, longestPath);
            }
        }


    }
    IO::writeln(longestPath);
    IO::writeln(*max_element(unmap.begin(), unmap.end()));
    return 0;
}
