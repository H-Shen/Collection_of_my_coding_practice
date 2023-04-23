using ll = long long;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<int, vector<ll>> unmap;
        for (int i = 0; i < n; ++i) {
            unmap[nums[i]].emplace_back(i);
        }
        vector<ll> arr(n);
        unordered_map<int, vector<ll>> unmap2pre = unmap;
        for (auto&[k,vList] : unmap2pre) {
            int length = (int)vList.size();
            for (int i = 1; i < length; ++i) {
                vList[i] += vList[i-1];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (unmap[nums[i]].size() < 2) {
                arr[i] = 0;
            }
            else {
                auto& value = unmap[nums[i]];
                int pos = (int)(lower_bound(value.begin(),value.end(),i) - value.begin());
                auto& preList = unmap2pre[nums[i]];
                if (pos == 0) {
                    // right
                    int r = (int)value.size()-1;
                    int l = pos+1;
                    arr[i] =  preList[r] - preList[l-1] - (ll)(value.size()-1)*i;
                }
                else if (pos == (int)value.size()-1) {
                    // left
                    int r = pos-1;
                    int l = 0;
                    arr[i] = (ll)(value.size()-1)*i - preList[r];
                }
                else {
                    // left
                    int r = pos-1;
                    int l = 0;
                    arr[i] += (ll)pos*i - preList[r];
                    // right
                    r = (int)value.size()-1;
                    l = pos+1;
                    arr[i] += preList[r] - preList[l-1] - (ll)(value.size()-(pos+1))*i;
                }
            }
        }
        return arr;
    }
};