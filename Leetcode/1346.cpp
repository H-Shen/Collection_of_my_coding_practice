class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        constexpr int MAXN = 4005;
        constexpr int OFFSET = 2000;
        bitset<MAXN> exist;
        int counterOfZero = 0;
        for (const auto &i : arr) {
            if (i == 0) counterOfZero++;
            exist[i + OFFSET] = true;
        }
        if (counterOfZero > 1) return true;
        for (const auto &i : arr) {
            if (exist[i + OFFSET] && exist[i * 2 + OFFSET] && i != 0) {
                return true;
            }
        }
        return false;
    }
};