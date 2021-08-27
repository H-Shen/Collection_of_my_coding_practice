class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        int item = n / 2;
        for (int i = 1; i <= item; ++i)  {
            res.emplace_back(i);
            res.emplace_back(-i);
        }
        if (n % 2 != 0) {
            res.emplace_back(0);
        }
        return res;
    }
};