#include <bits/extc++.h>

using namespace std;
using ll = long long;

template<typename T>
struct BIT {
    vector<T> t1, t2;
    int N;
    int lowbit(int i) {
        return i & (-i);
    }
    // index starts from 1
    BIT(int n) : N(n+1) {
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

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int main() {

    fast_io();
    int n, w;
    cin >> n >> w;
    int a, b;
    string op;
    BIT<ll> bit(n);
    while (w--) {
        cin >> op >> a >> b;
        if (op == "x") {
            bit.rupd(a,a,b);
        }
        else {
            cout << bit.rsum(a,b) << '\n';
        }
    }
    return 0;
}