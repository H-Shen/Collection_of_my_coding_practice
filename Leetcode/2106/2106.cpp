constexpr int MAXN = 2*1e5+5;

int pre[MAXN];

class Solution {
public:
    int rangeSum(int l, int r) {
        if (l == 0) return pre[r];
        return pre[r] - pre[l-1];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        memset(pre, 0, sizeof pre);
        for (auto&i : fruits) {
            pre[i[0]] = i[1];
        }
        for (int i = 1; i < MAXN; ++i) {
            pre[i] += pre[i-1]; 
        }
        int ans = 0;
        // 只能先左后右 或者先右后左
        // left then right
        for (int l = 0, r = k; r >= 0; ++l, r=k-2*l) {
            int leftPos = max(0,startPos - l);
            int rightPos = min(MAXN-1,startPos + r);
            ans = max(ans, rangeSum(leftPos, rightPos));
        }
        // right then left
        for (int l = k, r = 0; l >= 0; ++r, l=k-2*r) {
            int leftPos = max(0,startPos - l);
            int rightPos = min(MAXN-1,startPos + r);
            ans = max(ans, rangeSum(leftPos, rightPos));
        }
        return ans;
    }
};