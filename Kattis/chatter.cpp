// https://open.kattis.com/problems/chatter

#include <bits/extc++.h>

using namespace std;
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

namespace DSU {
    vector<int> father, Size;

    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }

    int find(int x) {
        if (x != father[x]) father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        father[x] = y;
        Size[y] += Size[x];
    }
}

int n, r, a, b, c, x, y;

int main() {
    while (IO::can_read(n)) {
        IO::read(r, a, b, c);
        DSU::init(n);
        r = (a * r + b) % c;
        for (int i = 0; i < n; ++i) {
            x = r % n;
            r = (a * r + b) % c;
            y = r % n;
            r = (a * r + b) % c;
            if (x == y) {
                x = r % n;
                r = (a * r + b) % c;
                y = r % n;
                r = (a * r + b) % c;
            }
            DSU::merge(x, y);
        }
        // group id to its size
        unordered_map<int, int> groupId2Size;
        for (int i = 0; i < n; ++i) {
            ++groupId2Size[DSU::find(i)];
        }
        // size to number of groups with such size
        unordered_map<int, int> size2Groups;
        for (const auto &i : groupId2Size) {
            ++size2Groups[i.second];
        }
        vector<pair<int, int> > vec(size2Groups.begin(), size2Groups.end());
        sort(vec.begin(), vec.end(), [](const auto &l, const auto &r) {
            return l.first > r.first;
        });
        IO::write(groupId2Size.size());
        putchar_unlocked(' ');
        bool firstItem = true;
        for (const auto &[k, v] : vec) {
            if (firstItem) {
                firstItem = false;
            } else {
                putchar_unlocked(' ');
            }
            if (v == 1) {
                IO::write(k);
            } else {
                IO::write(k);
                putchar_unlocked('x');
                IO::write(v);
            }
        }
        putchar_unlocked('\n');
    }

    return 0;
}
