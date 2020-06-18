#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define CODEFORCES

#ifdef CODEFORCES
namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = _getchar_nolock(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = _getchar_nolock();
        while (isdigit(c)) t = t * 10 + c - 48, c = _getchar_nolock();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, _putchar_nolock('-');
        if (x > 9) write(x / 10);
        _putchar_nolock(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        _putchar_nolock('\n');
    }
}
#else
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
#endif

vector<int> get_intersected(const unordered_set<int> &A, const unordered_set<int> &B) {
    vector<int> vec_A(A.begin(), A.end());
    vector<int> vec_B(B.begin(), B.end());
    sort(vec_A.begin(), vec_A.end());
    sort(vec_B.begin(), vec_B.end());
    vector<int> vec_C;
    set_intersection(vec_A.begin(), vec_A.end(), vec_B.begin(), vec_B.end(), back_inserter(vec_C));
    return vec_C;
}

int main() {

    int n, m, val;
    IO::read(n, m);
    unordered_set<int> A;
    while (n--) {
        IO::read(val);
        while (val > 0) {
            A.insert(val % 10);
            val /= 10;
        }
    }
    unordered_set<int> B;
    while (m--) {
        IO::read(val);
        while (val > 0) {
            B.insert(val % 10);
            val /= 10;
        }
    }
    auto intersected = get_intersected(A, B);
    if (intersected.empty()) {
        int minA = numeric_limits<int>::max();
        for (const auto &i : A) {
            minA = min(minA, i);
        }
        int minB = numeric_limits<int>::max();
        for (const auto &i : B) {
            minB = min(minB, i);
        }
        if (minA > minB) {
            swap(minA, minB);
        }
        IO::write(minA);
        IO::writeln(minB);
    } else {
        IO::writeln(*min_element(intersected.begin(), intersected.end()));
    }

    return 0;
}