// https://open.kattis.com/problems/numbersetseasy

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

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),  father.end(), 0);
        Size.resize(n+5, 1);
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
}


constexpr int MAXN = 1050;
vector<int> prime;
int n;

int c, a, b, p, counter, temp;

void pre() {
    prime.emplace_back(2);
    bool flag;
    for (int i = 3; i <= MAXN; ++i) {
        flag = false;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            prime.emplace_back(i);
        }
    }
    n = (int)prime.size();
}

int main() {
    pre();
    IO::read(c);
    for (int kase = 1; kase <= c; ++kase) {
        IO::read(a, b, p);
        DSU::init(b);
        temp = (int)(lower_bound(prime.begin(),prime.end(),p)-prime.begin());
        for (int i = temp; i < n; ++i) {
            if (prime[i] > b) {
                break;
            }
            counter = 1;
            while (counter * prime[i] < a) {
                ++counter;
            }
            int firstVal = counter * prime[i];
            while (counter * prime[i] <= b) {
                DSU::merge(counter * prime[i], firstVal);
                ++counter;
            }
        }
        unordered_set<int> groups;
        for (int i = a; i <= b; ++i) {
            groups.insert(DSU::find(i));
        }
        printf("Case #");
        IO::write(kase);
        printf(": ");
        IO::writeln(groups.size());
    }
    return 0;
}
