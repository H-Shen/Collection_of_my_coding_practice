using ll = long long;
constexpr ll P = 31;
constexpr ll M = 1e9+7;

class Solution {
public:
    string longestPrefix(string s) {
        int n = (int)s.size();
        if (n == 1) {
            return "";
        }
        vector<ll> Pow(n+5);
        Pow[0] = 1;
        for (int i = 1; i < n+5; ++i) {
            Pow[i] = Pow[i-1] * P % M;
        }
        unordered_map<ll, int> hash2length;
        // get rolling hash of each prefix excluding itself
        ll h = 0;
        for (int i = 0; i < n-1; ++i) {
            h = (h + Pow[i] * (ll)(s[i] - 'a' + 1)) % M;
            hash2length[h] = i+1;
        }
        // get rolling hash of each suffix excluding itself
        h = 0;
        vector<int> candids;
        for (int i = n-1; i > 0; --i) {
            h = (h * P % M + (ll)(s[i] - 'a' + 1) % M) % M;
            auto iter = hash2length.find(h);
            if (iter != hash2length.end() && iter->second == n - i) {
                candids.emplace_back(n - i);
                //cout << s.substr(0,iter->second) << ' ' << s.substr(i) << '\n';
            }
        }
        if (!candids.empty()) {
            bool found;
            for (auto iter = candids.rbegin(); iter != candids.rend(); ++iter) {
                // double check
                int temp = *iter;
                found = true;
                for (int i = 0, j = n-temp; i < temp; ++i, ++j) {
                    if (s[i] != s[j]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    return s.substr(0, temp);
                }
            }
        }
        
        return "";
    }
};