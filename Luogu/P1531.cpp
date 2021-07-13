#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct SegmentTree {
    // max: INF = numeric_limits<int>::min();
    // min: INF = numeric_limits<int>::max();
    static const int INF = numeric_limits<int>::min();
    vector<int> st, lz;
    int n;
    void build(int p, int l, int r, const vector<int> &A) {
        if (l == r) { st[p] = A[l]; return; }
        build(2*p, l, (l+r)/2, A);
        build(2*p+1, (l+r)/2+1, r, A);
        st[p] = max(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
    }
    SegmentTree() = default;
    SegmentTree(vector<int> &A) {
        n = (int)A.size();
        st.resize(n << 2);
        lz.resize(n << 2);
        // The p is id of the tree, which starts from root = 1
        build(1, 0, n - 1, A);
    }
    void push(int p, int l, int r) {
        if (lz[p]) {
            st[p] = lz[p];
            // RMQ -> add: = lz[p],         increment: += lz[p]
            // RSQ -> add: = (r-l+1)*lz[p], increment: += (r-l+1)*lz[p]
            if(l!=r) lz[2*p] = lz[2*p+1] = lz[p]; // add: =, increment +=
            lz[p] = 0;
        }
    }
    int query(int p, int l, int r, int i, int j) {
        push(p, l, r);
        if (r < i or l > j) return INF; // RMQ -> INF, RSQ -> 0
        if (l >= i and r <= j) return st[p];
        return max(query(2*p, l, (l+r)/2, i, j),
                   query(2*p+1, (l+r)/2+1, r, i, j));
        // RMQ -> min/max, RSQ -> +
    }
    void update(int p, int l, int r, int i, int j, int v) {
        push(p, l, r);
        if (r < i or l > j) return;
        if (l >= i and r <= j) { lz[p] = v; push(p, l, r); return; }
        update(2*p, l, (l+r)/2, i, j, v);
        update(2*p+1, (l+r)/2+1, r, i, j, v);
        st[p] = max(st[2*p], st[2*p+1]); // RMQ -> min/max, RSQ -> +
    }
};

int n, m, a, b, a_val;
vector<int> A;
SegmentTree st;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    A.resize(n);
    string s;
    for (auto &i : A) cin >> i;
    st.n = n;
    st.st.resize(n << 2);
    st.lz.resize(n << 2);
    st.build(1,0,n-1,A);
    while (m--) {
        cin >> s >> a >> b;
        if (s == "Q") {
            --a;
            --b;
            cout << st.query(1, 0, st.n - 1, a, b) << '\n';
        }
        else {
            --a;
            a_val = st.query(1, 0, st.n - 1, a, a);
            if (a_val < b) {
                st.update(1, 0, st.n - 1, a, a, b);
            }
        }
    }
    return 0;
}