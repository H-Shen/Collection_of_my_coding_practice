constexpr int MAXN = 32;

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        bitset<MAXN> bs;
        for (auto&i : nums) {
            bitset<MAXN> temp(i);
            for (int j = 0; j < MAXN; ++j) {
                if (temp[j] && !bs[j]) {
                    bs[j] = true;
                }
            }
        }
        return (int)bs.to_ulong();
    }
};