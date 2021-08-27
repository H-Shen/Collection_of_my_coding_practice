using ll = long long;


class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        // Rabin Karp
        constexpr int p = 31;
        constexpr int m = 1e9 + 9;
        constexpr int MAXN = 1005;
        int T = (int)s.size();
        vector<ll> p_pow(T);
        p_pow[0] = 1;
        for (int i = 1; i < T; i++) {
            p_pow[i] = (p_pow[i-1] * p) % m;
        }
        bitset<MAXN> isBold;
        vector<ll> h(T + 1, 0);
        for (int i = 0; i < T; i++) {
            h[i+1] = (h[i] + s[i] * p_pow[i]) % m;
        }
        auto f = [&](const string &pattern) {
            int P = (int)pattern.size();
            vector<int> occurrences;
            if (P > T) {
                return occurrences;
            }
            ll h_s = 0;
            for (int i = 0; i < P; i++) {
                h_s = (h_s + pattern[i] * p_pow[i]) % m;
            }
            for (int i = 0; i + P - 1 < T; i++) {
                ll cur_h = (h[i + P] + m - h[i]) % m;
                if (cur_h == h_s * p_pow[i] % m)
                    occurrences.push_back(i);
            }
            return occurrences;
        };
        int startIndex, endIndex;
        for (const auto &i : dict) {
            auto vec = f(i);
            for (const auto &j : vec) {
                startIndex = j;
                endIndex = j + (int)i.size() - 1;
                for (int k = startIndex; k <= endIndex; ++k) {
                    isBold[k] = true;
                }
            }
        }
        string result;
        bool inBold = false;
        for (int i = 0; i < T; ++i) {
            if (isBold[i]) {
                if (!inBold) {
                    inBold = true;
                    result += "<b>";
                }
            } else {
                if (inBold) {
                    result += "</b>";
                    inBold = false;
                }
            }
            result.push_back(s[i]);
        }
        if (inBold) {
            result += "</b>";
        }
        return result;
    }
};