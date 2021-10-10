class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        constexpr int MAXN = 105;
        bitset<MAXN> bs1, bs2, bs3;
        for (auto &i : nums1) bs1[i] = true;
        for (auto &i : nums2) bs2[i] = true;
        for (auto &i : nums3) bs3[i] = true;
        vector<int> vec;
        int counter;
        for (int i = 0; i < MAXN; ++i) {
            counter = 0;
            if (bs1[i]) ++counter;
            if (bs2[i]) ++counter;
            if (bs3[i]) ++counter;
            if (counter >= 2) vec.emplace_back(i);
        }
        return vec;
    }
};