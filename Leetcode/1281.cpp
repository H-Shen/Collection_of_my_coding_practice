class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        int temp;
        while (n > 0) {
            temp = n % 10;
            prod *= temp;
            sum += temp;
            n /= 10;
        }
        return prod - sum;
    }
};