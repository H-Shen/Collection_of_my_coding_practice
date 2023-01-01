class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        int val;
        int numCopy = num;
        while (num > 0) {
            val = num % 10;
            if (numCopy % val == 0) ++cnt;
            num /= 10;
        }
        return cnt;
    }
};