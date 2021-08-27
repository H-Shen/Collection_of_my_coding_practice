class Solution {
public:
    int sumDivisors(int n) {
        int sum = 0;
        int a, b;
        int counter = 0;
        for (int i = 1; i*i <= n; ++i) {
            if (n % i == 0) {
                a = i;
                b = n / i;
                if (a == b) {
                    ++counter;
                    sum += a;
                } else {
                    counter += 2;
                    sum += a;
                    sum += b;
                }
                if (counter > 4) {
                    return 0;
                }
            }
        }
        if (counter < 4) {
            return 0;
        }
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (const auto &i : nums) {
            ans += sumDivisors(i);
        }
        return ans;
    }
};