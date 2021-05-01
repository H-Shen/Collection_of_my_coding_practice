class Solution {
public:
    int candy(vector<int>& ratings) {
        // greedy
        // requirement
        // 1. If ratings[i-1] < ratings[i], i gets at least 1 more candy than i-1
        // 2. If ratings[i] > ratings[i+1], i gets at least 1 more candy than i+1
        int n = (int)ratings.size();
        // scan from left to right
        vector<int> left(n+1);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                left[i] = 1;
                continue;
            }
            if (ratings[i] > ratings[i-1]) {
                left[i] = left[i-1]+1;
            } else {
                left[i] = 1;
            }
        }
        // scan from right to left
        vector<int> right(n+1);
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                right[i] = 1;
                continue;
            }
            if (ratings[i] > ratings[i+1]) {
                right[i] = right[i+1]+1;
            } else {
                right[i] = 1;
            }
        }
        // for each entry in index i, get max(left[i], right[i]) since it meets both requirements
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += max(left[i], right[i]);
        }
        return ans;
    }
};