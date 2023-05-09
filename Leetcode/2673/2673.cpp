class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        int r, l;
        for (int i = n; i > 1; i -= 2) {
            r = i;
            l = i-1;
            ans += abs(cost[r-1] - cost[l-1]);
            cost[(l>>1)-1] += max(cost[r-1], cost[l-1]);
        }
        return ans;
    }
};