// https://open.kattis.com/problems/stringmultimatching

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace SA {
    vector<int> sa, ra;
    string s;
    void reset() {
        vector<int>().swap(sa);
        vector<int>().swap(ra);
    }
    void csort(int l, int k) {
        int m = max(300, l + 1);
        vector<int> c(m);
        vector<int> sa2(l);
        for (int i = 0; i < l; ++i) {
            c[i+k<l?ra[i+k]+1:0]++;
        }
        for (int s_ = 0, i = 0; i < m; ++i) {
            swap(c[i], s_);
            s_ += c[i];
        }
        for (int i = 0; i < l; ++i) {
            sa2[c[sa[i]+k<l ? ra[sa[i]+k]+1 : 0]++] = sa[i];
        }
        sa = sa2;
    }
    void init() {
        int l = (int)s.size();
        sa.resize(l);
        iota(sa.begin(), sa.end(), 0);
        ra.assign(s.begin(), s.end());
        for (int k = 1; k < l; k *= 2) {
            csort(l, k);
            csort(l, 0);
            /*
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (ra[a] != ra[b]) {
                    return ra[a] < ra[b];
                }
                int ak = a + k < l ? ra[a + k] : -1;
                int bk = b + k < l ? ra[b + k] : -1;
                return ak < bk;
            });*/
            vector<int> ra2(l);
            int x = 0;
            for (int i = 1; i < l; ++i) {
                if (ra[sa[i]] != ra[sa[i - 1]] ||
                    sa[i - 1] + k >= l ||
                    ra[sa[i] + k] != ra[sa[i-1]+k]) {
                    ++x;
                }
                ra2[sa[i]] = x;
            }
            ra = ra2;
        }
    }
    void saFind(const string &pattern) {
        auto r = equal_range(sa.begin(), sa.end(), -1, [&](int i, int j) {
            int a = 1;
            if (i == -1) {
                swap(i, j);
                a = -1;
            }
            return a*s.compare(i, pattern.size(), pattern) < 0;
        });
        vector occ(r.first, r.second);
        sort(occ.begin(), occ.end());
        for (const auto &i : occ) cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (true) {
        if (!(cin >> n)) break;
        cin.get();
        vector<string> pattern(n);
        for (auto &i : pattern) getline(cin, i);
        getline(cin, SA::s);
        SA::init();
        for (const auto &i : pattern) {
            SA::saFind(i);
        }
        SA::reset();
    }
    return 0;
}
