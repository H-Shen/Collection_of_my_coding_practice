class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        if (x == 1 && y == 1) {
            if (bound >= 2) {
                ans.emplace_back(2);
            }
        }
        else if (x == 1 && y != 1) {
            if (bound >= 1) {
                int temp = 1;
                while (x + temp <= bound) {
                    ans.emplace_back(x + temp);
                    temp *= y;
                }
            }
        }
        else if (x != 1 && y == 1) {
            if (bound >= 1) {
                int temp = 1;
                while (y + temp <= bound) {
                    ans.emplace_back(y + temp);
                    temp *= x;
                }
            }
        }
        else {
            unordered_set<int> unset;
            for (int i = 1; i <= bound; i*=x) {
                for (int j = 1; j+i <= bound; j*= y) {
                    unset.insert(j+i);
                }
            }
            for (auto &i : unset) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};