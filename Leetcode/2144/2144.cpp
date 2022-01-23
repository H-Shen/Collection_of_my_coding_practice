class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = (int)cost.size();
        if (n == 1) return cost[0];
        else if (n == 2) return cost[0]+cost[1];
        sort(cost.begin(),cost.end(),greater<>());
        int ans = 0;
        int a, b;
        for (int i = 0; i < n;) {
            if (i+1==n) {
                ans += cost[i];
                break;
            }
            else if (i+2==n) {
                ans += cost[i] + cost[i+1];
                break;
            }
            else {
                ans += cost[i] + cost[i+1];
                i += 3;
            }
        }
        return ans;
    }
};