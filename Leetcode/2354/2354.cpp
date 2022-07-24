using ll = long long;

class Solution {
public:
    inline
    ll rangeSum(vector<ll>&pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_map<int,unordered_set<int>> freq;
        // The sum of the number of set bits in (num1 OR num2) and (num1 AND num2) is equal to the sum of the number of set bits in num1 and num2.
        for (auto&i : nums) {
            int temp = (int)__builtin_popcount(i);
            freq[temp].insert(i);
        }
        vector<pair<int,unordered_set<int>>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            return l.first < r.first;
        });
        int n = (int)vec.size();
        vector<ll> pre(n);
        pre[0] = (ll)vec[0].second.size();
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + (ll)vec[i].second.size();
        }
        ll result = 0;
        pair<int,unordered_set<int>> p;
        for (int i = 0; i < n; ++i) {
            p.first = k - vec[i].first;
            auto iter = lower_bound(vec.begin(),vec.end(),p,[](const auto &l, const auto &r){
                return l.first < r.first;
            });
            if (iter != vec.end()) {
                int pos = (int)(iter - vec.begin());
                if (pos > i) {
                    result += (ll)vec[i].second.size() * rangeSum(pre, pos, n-1);
                }
                else {
                    // self
                    result += (ll)vec[i].second.size() * (ll)vec[i].second.size();
                    // right
                    if (i < n-1) {
                        result += (ll)vec[i].second.size() * rangeSum(pre, i+1, n-1);
                    }
                    // left
                    if (pos < i) {
                        result += (ll)vec[i].second.size() * rangeSum(pre, pos, i-1);
                    }
                }
            }
        }
        return result;
    }
};