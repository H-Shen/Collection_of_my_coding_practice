// https://open.kattis.com/problems/rings
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;

inline
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
}

struct Circle {
    double x, y, r;
    explicit Circle(double x, double y, double r) : x(x), y(y), r(r) {}
};

inline
bool is_glued(const Circle &l, const Circle &r) {
    double temp = (l.x-r.x)*(l.x-r.x) + (l.y-r.y)*(l.y-r.y);
    return sgn(temp - (l.r+r.r)*(l.r+r.r) ) < 0 && sgn(temp - (l.r-r.r)*(l.r-r.r)) > 0;
}

int main(int argc, char *argv[]) {

    int n;
    double x, y, r;
    while (true) {
        scanf("%d", &n);
        if (n == -1) break;
        DSU::init(n);
        vector<Circle> A;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &x, &y, &r);
            A.emplace_back(Circle(x, y, r));
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (is_glued(A.at(i), A.at(j))) {
                    DSU::merge(i, j);
                }
            }
        }
        gp_hash_table<int, int, custom_hash> groups;
        for (int i = 0; i < n; ++i) {
            ++groups[DSU::find(i)];
        }
        int counter = 0;
        for (const auto &[k, v] : groups) {
            counter = max(counter, v);
        }
        printf("The largest component contains %d ring", counter);
        if (counter > 1) {
            printf("s.\n");
        } else {
            printf(".\n");
        }
    }
    return 0;
}
