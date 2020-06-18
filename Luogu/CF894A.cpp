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

constexpr int MAXN = 105;
char cstr[MAXN];
unordered_map<char, vector<int> > A;

int main() {

    scanf("%s", cstr);
    for (int i = 0; cstr[i] != 0; ++i) {
        if (cstr[i] == 'Q' || cstr[i] == 'A') {
            A[cstr[i]].emplace_back(i);
        }
    }
    ll sum = 0;
    // Choose first Q
    for (auto iter = A['Q'].begin(); iter != A['Q'].end(); ++iter) {
        // Choose A that is after Q
        size_t start_index = lower_bound(A['A'].begin(), A['A'].end(), *iter) - A['A'].begin();
        for (; start_index != A['A'].size(); ++start_index) {
            // Choose the number of Qs that is after current A
            sum += A['Q'].end() - lower_bound(A['Q'].begin(), A['Q'].end(), A['A'].at(start_index));
        }
    }
    printf("%lld\n", sum);

    return 0;
}