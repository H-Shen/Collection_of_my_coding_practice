// https://open.kattis.com/problems/massivecardgame

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

template<typename T>
struct BIT {
    vector<T> t1, t2;
    int N;
    int lowbit(int i) {
        return i & (-i);
    }
    // index starts from 1
    BIT(int n) : N(n+5) {
        t1.resize(N);
        t2.resize(N);
    }
    T sum(const vector<T> &t, int n) {
        T a(0);
        while (n) {
            a += t[n];
            n -= lowbit(n);
        }
        return a;
    }
    T rsum(int n) {
        return sum(t1,n)*n-sum(t2,n);
    }
    T rsum(int l, int r) {
        return rsum(r)-rsum(l-1);
    }
    void upd(vector<T> &t, int n, T val) {
        while (n < N) {
            t[n] += val;
            n += lowbit(n);
        }
    }
    void rupd(int l, int r, T val) {
        upd(t1,l,val);
        upd(t1,r+1,-val);
        upd(t2,l,val*(l-1));
        upd(t2,r+1,-val*r);
    }
};

constexpr int MAXN = 1000005;  // not 100005 here!
BIT<int> bit(MAXN);
int n, q, l, r;
vector<int> vec, mapping;
vector<pair<int,int>> query;

int main() {
    IO::read(n);
    vec.resize(n);
    for (auto &i : vec) IO::read(i);
    mapping = vec;
    IO::read(q);
    query.resize(q);
    for (int i = 0; i < q; ++i) {
        IO::read(query[i].first, query[i].second);
        mapping.emplace_back(query[i].first);
        mapping.emplace_back(query[i].second);
    }
    sort(mapping.begin(),mapping.end());
    mapping.erase(unique(mapping.begin(),mapping.end()), mapping.end());
    // add freq to BIT
    for (auto &i : vec) {
        l = (int)(lower_bound(mapping.begin(),mapping.end(),i) - mapping.begin()) + 1;
        r = l;
        bit.rupd(l, r, 1);
    }
    for (auto &[i, j] : query) {
        l = (int)(lower_bound(mapping.begin(),mapping.end(),i) - mapping.begin()) + 1;
        r = (int)(lower_bound(mapping.begin(),mapping.end(),j) - mapping.begin()) + 1;
        IO::writeln(bit.rsum(l, r));
    }
    return 0;
}
