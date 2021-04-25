// https://open.kattis.com/problems/classpicture

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

constexpr int MAXN = 15;

int main() {

    fast_io();
    int n;
    while (cin >> n) {
        if (n == 1) {
            string s;
            cin >> s;
            int m;
            cin >> m;
            cout << s << '\n';
        } else {
            vector<string> A(n);
            for (auto &i : A) cin >> i;
            sort(A.begin(), A.end());
            unordered_map<string, int> unmap;
            for (int i = 0; i < n; ++i) {
                unmap[A[i]] = i;
            }
            string u_s, v_s;
            int m, u, v;
            cin >> m;
            bitset<MAXN> conflict[MAXN];
            while (m--) {
                cin >> u_s >> v_s;
                u = unmap[u_s];
                v = unmap[v_s];
                conflict[u][v] = true;
                conflict[v][u] = true;
            }
            vector<int> perm(n);
            iota(perm.begin(), perm.end(), 0);
            bool haveAns = false;
            bool hasConflict;
            do {
                hasConflict = false;
                for (int i = 0; i < n - 1; ++i) {
                    if (conflict[perm[i]][perm[i + 1]]) {
                        hasConflict = true;
                        break;
                    }
                }
                if (!hasConflict) {
                    haveAns = true;
                    for (int i = 0; i < n; ++i) {
                        if (i == 0) {
                            cout << A[perm[i]];
                        } else {
                            cout << ' ' << A[perm[i]];
                        }
                    }
                    cout << '\n';
                    break;
                }
            } while (next_permutation(perm.begin(), perm.end()));
            if (!haveAns) {
                cout << "You all need therapy." << '\n';
            }
        }
    }

    return 0;
}
