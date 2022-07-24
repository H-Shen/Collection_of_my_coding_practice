using ll = long long;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<ll> vec;
        ll freq = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                ++freq;
            }
            else {
                if (freq > 0) {
                    vec.emplace_back(freq);
                    freq = 0;
                }
            }
        }
        if (freq > 0) {
            vec.emplace_back(freq);
        }
        ll result = 0;
        for (const auto &i : vec) {
            result += (((1+i)*i)>>1);
        }
        return result;
    }
};