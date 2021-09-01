class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n, 'a');
        int sum = n;
        int i = n - 1;
        while (sum < k) {
            if (sum + 25 <= k) {
                ans[i] = 'z';
                --i;
                sum += 25;
            } else {
                ans[i] += k - sum;
                break;
            }
        }
        return ans;
    }
};