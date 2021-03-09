#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ld = long double;
using int128 = __int128;
using ii = pair<int, int>;
using vii = vector<pair<int, int>>;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct SegmentTree {
    static const ll INF = numeric_limits<ll>::min();
    vector<ll> st, lz;
    int n;
    void build(int p, int l, int r, const vector<ll> &A) {
        if (l == r) { st[p] = A[l]; return; }
        build(2*p, l, (l+r)/2, A);
        build(2*p+1, (l+r)/2+1, r, A);
        st[p] = max(st[2*p], st[2*p+1]);
    }
    SegmentTree() = default;
    SegmentTree(vector<ll> &A) {
        n = (int)A.size();
        st.resize(n << 2);
        lz.resize(n << 2);
        build(1, 0, n - 1, A);
    }
    void push(int p, int l, int r) {
        if (lz[p]) {
            st[p] = lz[p];
            if(l!=r) lz[2*p] = lz[2*p+1] = lz[p];
            lz[p] = 0;
        }
    }
    ll query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (r < i or l > j) {
            return INF;
        }
        if (l >= i and r <= j) return st[p];
        return max(query(2*p, l, (l+r)/2, i, j),
                   query(2*p+1, (l+r)/2+1, r, i, j));
    }
    void update(int p, int l, int r, int i, int j, ll v) {
        push(p, l, r);
        if (r < i or l > j) return;
        if (l >= i and r <= j) { lz[p] = v; push(p, l, r); return; }
        update(2*p, l, (l+r)/2, i, j, v);
        update(2*p+1, (l+r)/2+1, r, i, j, v);
        st[p] = max(st[2*p], st[2*p+1]);
    }
};

ll t;
int counter;
SegmentTree st;
int main() {

    fast_io();
    int M;
    ll D;
    cin >> M >> D;
    st.n = M;
    st.st.resize(st.n << 2);
    st.lz.resize(st.n << 2);
    string s; ll val;
    for (int i = 0; i < M; ++i) {
        cin >> s >> val;
        if (s == "A") {
            st.update(1, 0, st.n - 1, counter, counter, (val + t) % D);
            ++counter;
        }
        else {
            int r = counter - 1;
            int l = r + 1 - (int)val;
            t = st.query(1, 0, st.n-1, l, r);
            cout << t << '\n';
        }
    }

    return 0;
}