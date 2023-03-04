constexpr int N = 11;

class Solution {
public:
    int splitNum(int num) {
        string s = to_string(num);
        string num1, num2;
        int result = numeric_limits<int>::max();
        int n = (int)s.size();
        int tot = (1<<n)-1;
        for (int i = 1; i < tot; ++i) {
            bitset<N> bs(i);
            num1.clear();
            num2.clear();
            for (int j = 0; j < n; ++j) {
                if (bs[j]) {
                    num1.push_back(s[j]);
                }
                else {
                    num2.push_back(s[j]);
                }
            }
            sort(num1.begin(),num1.end());
            sort(num2.begin(),num2.end());
            result = min(result, stoi(num1) + stoi(num2));
        }
        return result;
    }
};