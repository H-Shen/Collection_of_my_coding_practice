class Solution {
public:
    int numberCount(int a, int b) {
        constexpr int N = 10;
        int cnt = 0;
        int temp;
        bool hasAns;
        for (int i = a; i <= b; ++i) {
            int freq[N]{};
            temp = i;
            hasAns = true;
            while (temp > 0) {
                ++freq[temp % 10];
                if (freq[temp % 10] > 1) {
                    hasAns = false;
                    break;
                }
                temp /= 10;
            }
            if (hasAns) {
                ++cnt;
            }
        }
        return cnt;
    }
};