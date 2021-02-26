// https://open.kattis.com/problems/stringmultimatching

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// An implementation of Suffix Array with Induced-Sort
// Can construct SA in O(n)
namespace SA {
    constexpr bool L_TYPE = false;
    constexpr bool S_TYPE = !L_TYPE;
    vector<int> sais(const vector<int> &s) {

        int n = (int) s.size() - 1;
        int maxValue = *max_element(s.begin(), s.end()) + 1;
        vector<int> SA(n + 1, -1);
        vector<int> bucket(maxValue), lbucket(maxValue), sbucket(maxValue);

        for (auto x : s) ++bucket[x];
        for (int i = 1; i < maxValue; ++i) {
            bucket[i] += bucket[i - 1];
            lbucket[i] = bucket[i - 1];
            sbucket[i] = bucket[i] - 1;
        }

        // Confirm the type and the position of '*'
        vector<bool> type(n + 1);
        type[n] = S_TYPE;
        for (int i = n - 1; i >= 0; --i) {
            type[i] = (s[i] < s[i + 1] ? S_TYPE : (s[i] > s[i + 1] ? L_TYPE : type[i + 1]));
        }

        // Define helper lambda functions
        auto is_lms_char = [&](int i) {
            return i > 0 && type[i] == S_TYPE && type[i - 1] == L_TYPE;
        };
        auto equal_substring = [&](int x, int y) {
            do {
                if (s[x] != s[y]) return false;
                ++x;
                ++y;
            } while (!is_lms_char(x) && !is_lms_char(y));
            return s[x] == s[y];
        };
        auto induced_sort = [&]() {
            for (int i = 0; i <= n; ++i) {
                if (SA[i] > 0 && type[SA[i] - 1] == L_TYPE) {
                    SA[lbucket[s[SA[i] - 1]]++] = SA[i] - 1;
                }
            }
            for (int i = 1; i < maxValue; ++i) {
                sbucket[i] = bucket[i] - 1;
            }
            for (int i = n; i >= 0; --i) {
                if (SA[i] > 0 && type[SA[i] - 1] == S_TYPE) {
                    SA[sbucket[s[SA[i] - 1]]--] = SA[i] - 1;
                }
            }
        };

        vector<int> pos;
        for (int i = 1; i <= n; ++i) {
            if (type[i] == S_TYPE && type[i - 1] == L_TYPE) {
                pos.emplace_back(i);
            }
        }
        for (auto x : pos) SA[sbucket[s[x]]--] = x;
        induced_sort();
        vector<int> name(n + 1, -1);
        int lx = -1, cnt = 0;
        bool flag = true;
        for (const auto &x : SA) {
            if (is_lms_char(x)) {
                if (lx >= 0 && !equal_substring(lx, x)) {
                    ++cnt;
                }
                if (lx >= 0 && cnt == name[lx]) {
                    flag = false;
                }
                name[x] = cnt;
                lx = x;
            }
        }
        vector<int> s1;
        for (const auto &x : name) {
            if (x != -1) {
                s1.emplace_back(x);
            }
        }
        vector<int> sa1;
        if (flag) {
            int n1 = s1.size();
            sa1.resize(n1);
            for (int i = 0; i < n1; ++i) sa1[s1[i]] = i;
        } else {
            sa1 = sais(s1);
        }
        lbucket[0] = sbucket[0] = 0;
        for (int i = 1; i < maxValue; ++i) {
            lbucket[i] = bucket[i - 1];
            sbucket[i] = bucket[i] - 1;
        }

        fill(SA.begin(), SA.end(), -1);
        for (int i = (int) sa1.size() - 1; i >= 0; --i) {
            SA[sbucket[s[pos[sa1[i]]]]--] = pos[sa1[i]];
        }
        induced_sort();
        return SA;
    }

    vector<int> sa;
    void init(const string &str) {
        vector<int> s(str.begin(), str.end());
        s.emplace_back(0);
        sa = sais(s);
        sa = vector<int>(sa.begin() + 1, sa.end());
    }

    void saFind(const string &pattern, const string &text) {
        auto r = equal_range(sa.begin(), sa.end(), -1, [&](int i, int j) {
            int a = 1;
            if (i == -1) {
                swap(i, j);
                a = -1;
            }
            return a * text.compare(i, pattern.size(), pattern) < 0;
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
    string text;
    while (true) {
        if (!(cin >> n)) break;
        cin.get();
        vector<string> pattern(n);
        for (auto &i : pattern) getline(cin, i);
        getline(cin, text);
        SA::init(text);
        for (const auto &i : pattern) {
            SA::saFind(i, text);
        }
    }
    return 0;
}
