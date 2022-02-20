class Solution {
public:
    int f(int n) {
        if (n == 0) return 0;
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countEven(int num) {
        int counter = 0;
        for (int i = 1; i <= num; ++i) {
            if (!(f(i) & 1)) {
                ++counter;
            }
        }
        return counter;
    }
};