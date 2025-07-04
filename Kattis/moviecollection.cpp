#include <iostream>
#include <vector>

using namespace std;

// Fenwick (BIT) for point updates and prefix-sums
class Fenwick {
    int n;
    vector<int> f;
public:
    explicit Fenwick(const int _n) : n(_n), f(n+1, 0) {}
    // add v at position i
    void update(int i, int v) {
        for (; i <= n; i += i & -i)
            f[i] += v;
    }
    // sum of [1..i]
    [[nodiscard]] int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += f[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int m, r;
        cin >> m >> r;

        // positions range 1..(r+m)
        Fenwick bit(r + m);
        vector<int> pos(m+1);

        // initial positions: movie i at (r + i)
        for (int i = 1; i <= m; ++i) {
            pos[i] = r + i;
            bit.update(pos[i], 1);
        }

        int next_top = r; // next free slot at top
        for (int i = 0; i < r; ++i) {
            int a;
            cin >> a;
            // number of movies above = count in [1..pos[a]-1]
            int above = bit.query(pos[a] - 1);
            cout << above << (i+1 < r ? ' ' : '\n');

            // remove from old position
            bit.update(pos[a], -1);
            // move to new top
            pos[a] = next_top;
            bit.update(pos[a], +1);
            --next_top;
        }
    }
    return 0;
}
