constexpr int MAXN = 26;

class Solution {
public:
    int minimumKeypresses(string s) {
        int freq[MAXN]{};
        for (auto& ch : s) {
            ++freq[ch - 'a'];
        }
        vector<pair<char,int>> vec;
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] > 0) {
                vec.emplace_back(i + 'a', freq[i]);
            }
        }
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.second > r.second;
        });
        int ans = 0;
        int pos = 1;
        for (auto& [i, j] : vec) {
            if (pos >= 1 && pos <= 9) {
                ans += j;
            }
            else if (pos >= 10 && pos <= 18) {
                ans += 2*j;
            }
            else {
                ans += 3*j;
            }
            ++pos;
        }
        return ans;
    }
};