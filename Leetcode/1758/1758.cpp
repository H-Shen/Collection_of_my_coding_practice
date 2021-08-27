class Solution {
public:
    int minOperations(string s) {
        if (s.size() <= 1) return 0;
        int n = (int)s.size();
        // 0101...
        int counter1 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0 && s[i] == '1') {
                ++counter1;
            }
            else if (i % 2 != 0 && s[i] == '0') {
                ++counter1;
            }
        }
        // 1010...
        int counter2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0 && s[i] == '0') {
                ++counter2;
            }
            else if (i % 2 != 0 && s[i] == '1') {
                ++counter2;
            }
        }
        return min(counter1, counter2);
    }
};