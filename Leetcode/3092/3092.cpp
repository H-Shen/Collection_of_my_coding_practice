using ll = long long;

unordered_map<int, ll> unmap;

struct Comparator {
    bool operator ()(const pair<int,ll>&l, const pair<int,ll>& r) const {
        if (l.second == r.second) {
            return l.first > r.first;
        }
        return l.second > r.second;
    }
};

set<pair<int,ll>, Comparator> s;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unmap.clear();
        s.clear();
        int n = (int)nums.size();
        vector<ll> ans(n);
        pair<int,ll> temp;
        for (int i = 0; i < n; ++i) {
            temp.first = nums[i];
            if (unmap.count(nums[i]) == 0) {
                unmap[nums[i]] = 0;
            }
            temp.second = unmap[nums[i]];
            s.erase(temp);
            unmap[nums[i]] += (ll)freq[i];
            temp.second = unmap[nums[i]];
            if (temp.second == 0) {
                s.erase(temp);
            }
            else {
                s.insert(temp);
            }
            
            if (s.empty()) {
                ans[i] = 0;
            }
            else {
                ans[i] = s.begin()->second;
            }
        }
        return ans;
    }
};