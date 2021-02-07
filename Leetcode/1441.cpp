class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        constexpr int MAXN = 105;
        bitset<MAXN> exist;
        vector<string> result;
        for (const auto &i : target) exist[i] = true;
        for (int i = 1; i <= target.back(); ++i) {
            result.emplace_back("Push");
            if (!exist[i]) {
                result.emplace_back("Pop");
            }
        }
        return result;
    }
};