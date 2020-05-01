// https://open.kattis.com/problems/undetected
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int X_UPPER_BOUND = 200;

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

namespace DSU {
    vector<int> father;
    vector<int> Size;

    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }

    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }

    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

struct Circle {
    int x, y, r;

    explicit Circle(int x, int y, int r) : x(x), y(y), r(r) {}

    Circle() = delete;
};

bool is_intersected(const Circle &lhs, const Circle &rhs) {
    return (lhs.x - rhs.x) * (lhs.x - rhs.x) +
           (lhs.y - rhs.y) * (lhs.y - rhs.y) <=
           (lhs.r + rhs.r) * (lhs.r + rhs.r);
}

int main() {

    int n, x, y, r, length, left, right;
    IO::read(n);
    left = n + 2;
    right = n + 3;
    DSU::init(n);
    vector<Circle> A;
    for (int i = 0; i < n; ++i) {
        IO::read(x, y, r);
        Circle temp(x, y, r);
        length = static_cast<int>(A.size());
        for (int j = 0; j < length; ++j) {
            if (is_intersected(temp, A.at(j))) {
                DSU::merge(i, j);
            }
        }
        A.emplace_back(temp);
        if (is_intersected(temp, Circle(0, y, 0))) {
            DSU::merge(i, left);
        }
        if (is_intersected(temp, Circle(X_UPPER_BOUND, y, 0))) {
            DSU::merge(i, right);
        }
        if (DSU::is_same_group(left, right)) {
            IO::writeln(i);
            return 0;
        }
    }

    return 0;
}
