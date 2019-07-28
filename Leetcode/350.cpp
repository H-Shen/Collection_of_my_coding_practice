class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        auto freqCnt = [](const vector<int> &a) -> unordered_map<int, int> {
            unordered_map<int, int> res;
            for (const auto &i : a) {
                ++res[i];
            }
            return res;
        };

        unordered_map<int, int> nums1_map = freqCnt(nums1);
        unordered_map<int, int> nums2_map = freqCnt(nums2);
        vector<int> res;
        int maxFreq;
        for (const auto &it : nums1_map) {
            if (nums2_map.find(it.first) != nums2_map.end()) {
                maxFreq = min(it.second, nums2_map[it.first]);
                for (int i = 0; i < maxFreq; ++i) {
                    res.push_back(it.first);
                }
            }
        }
        return res;
    }
};