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

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
    string to_string() const {
        return ::to_string(x) + " " + ::to_string(y);
    }
};

// Ax + By + C = 0
struct Line {
    int A, B, C;
    Line(const Point &a, const Point &b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = a.x*b.y-b.x*a.y;
        simplify();
    }
    void simplify() {
        if (A < 0) {
            A = -A;
            B = -B;
            C = -C;
        }
        vector<int> nonZero;
        for (auto i : {A, B, C}) {
            if (i != 0) {
                nonZero.emplace_back(i);
            }
        }
        if (!nonZero.empty()) {
            int gcdTmp = accumulate(nonZero.begin(), nonZero.end(), nonZero[0], ::gcd<int, int>);
            A /= gcdTmp;
            B /= gcdTmp;
            C /= gcdTmp;
        }
    }
    string to_string() const {
        return ::to_string(A) + " " + ::to_string(B) + " " + ::to_string(C);
    }
};

inline
std::ostream &operator<<(std::ostream &os, const Line &v) {
    os << v.A << " " << v.B << " " << v.C;
    return os;
}

struct hash_func_for_Pair {
    size_t operator ()(const pair<int, int> &obj) const {
        return hash<int>()(obj.first) ^ hash<int>()(obj.second);
    }
};
struct hash_func_for_Tuple {
    size_t operator ()(const tuple<int, int, int> &obj) const {
        return hash<int>()(get<0>(obj)) ^ hash<int>()(get<1>(obj)) ^ hash<int>()(get<2>(obj));
    }
};

int getMaxColinearPoints(const vector<Point> &A) {
    if (A.size() == 1) {
        return 1;
    }
    int n = static_cast<int>(A.size());
    unordered_map<tuple<int, int, int>, unordered_set<pair<int, int>, hash_func_for_Pair>, hash_func_for_Tuple > LineCollection;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            Line tmp(A[i], A[j]);
            auto temp = make_tuple(tmp.A, tmp.B, tmp.C);
            LineCollection[temp].insert(make_pair(A[i].x, A[i].y));
            LineCollection[temp].insert(make_pair(A[j].x, A[j].y));
        }
    }
    int result = -1;
    for (const auto &i : LineCollection) {
        result = max(result, static_cast<int>(i.second.size()));
    }
    return result;
}

int main() {

    int n;
    IO::read(n);
    vector<Point> A(n);
    for (auto &i : A) IO::read(i.x, i.y);
    IO::writeln(getMaxColinearPoints(A));

    return 0;
}
