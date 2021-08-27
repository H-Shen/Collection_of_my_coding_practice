class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        using ll = long long;
        vector<pair<ll, ll> > ranges;
        auto iter = nums.begin();
        bool firstItem = true;
        ll last, curr;
        while (iter != nums.end()) {
            if (firstItem) {
                last = *iter;
                curr = last;
                firstItem = false;
            } else {
                if (*iter - curr != 1) {
                    ranges.push_back({last, curr});
                    last = *iter;
                    curr = last;
                } else {
                    curr = *iter;
                }
            }
            ++iter;
        }
        if (!firstItem) {
            ranges.push_back({last, curr});
        }
        vector<string> result;
        for (const auto &[k, v] : ranges) {
            if (k == v) {
                result.emplace_back(to_string(k));
            } else {
                result.emplace_back(to_string(k) + "->" + to_string(v));
            }
        }
        return result;
    }
};