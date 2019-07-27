class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {

        auto selfDividingCheck = [](const int &a_copy) -> bool {
            int a(a_copy);
            int tmp;
            while (a > 0) {
                tmp = a % 10;
                if (tmp == 0 || a_copy % tmp != 0) {
                    return false;
                }
                a /= 10;
            }
            return true;
        };

        vector<int> res;
        for (int i = left; i <= right; ++i) {
            if (selfDividingCheck(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};