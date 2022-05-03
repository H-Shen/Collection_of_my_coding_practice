constexpr int GAP = 1e5;
constexpr int MAXN = 2*GAP+5;
int vis[MAXN];

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        memset(vis, 0, sizeof vis);
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            ++vis[nums[i] + GAP];
        }
        vector<int> numsCopy(n);
        int pos = 0;
        for (int i = 0; i < MAXN; ++i) {
            while (vis[i] > 0) {
                numsCopy[pos] = i - GAP;
                --vis[i];
                ++pos;
            }
        }
        int l = -1, r = -1;
        for (int i = 0; i < n; ++i) {
            if (numsCopy[i] != nums[i]) {
                l = i;
                break;
            }
        }
        for (int i = n-1; i >= 0; --i) {
            if (numsCopy[i] != nums[i]) {
                r = i;
                break;
            }
        }
        return (l == -1) ? 0 : r-l+1;
    }
};