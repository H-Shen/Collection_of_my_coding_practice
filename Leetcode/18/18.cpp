class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        using ll = long long;
        unordered_map<ll, vector<pair<int,int> > > unmap;
        int n = (int)nums.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                unmap[nums[i]+nums[j]].emplace_back(i,j);
            }
        }
        vector<vector<int> > ans;
        for (const auto &[k,v] : unmap) {
            ll diff = (ll)target - k;
            if (unmap.find(diff) != unmap.end()) {
                if (diff == k) {
                    // C(n, 2)
                    int length = (int)v.size();
                    for (int i = 0; i < length - 1; ++i) {
                        for (int j = i+1; j < length; ++j) {
                            if ( (v[i].first == v[j].first || v[i].first == v[j].second) || (v[i].second == v[j].first || v[i].second == v[j].second) ) {
                                continue;
                            }
                            ans.emplace_back(vector<int>{nums[v[i].first],nums[v[i].second],nums[v[j].first],nums[v[j].second]});
                        }
                    }
                }
                else {
                    // C(m, 1) * C(n, 1)
                    auto &v2 = unmap[diff];
                    int length1 = (int)v.size();
                    int length2 = (int)v2.size();
                    for (int i = 0; i < length1; ++i) {
                        for (int j = 0; j < length2; ++j) {
                            if ( (v[i].first == v2[j].first || v[i].first == v2[j].second) || (v[i].second == v2[j].first || v[i].second == v2[j].second) ) {
                                continue;
                            }
                            ans.emplace_back(vector<int>{nums[v[i].first],nums[v[i].second],nums[v2[j].first],nums[v2[j].second]});
                        }
                    }
                }
            }
        }
        for (auto &i : ans) {
            sort(i.begin(), i.end());
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()), ans.end());
        return ans;
    }
};