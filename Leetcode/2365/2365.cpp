using ll = long long;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        int n = (int)tasks.size();
        unordered_map<int,ll> unmap;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (unmap.count(tasks[i]) == 0) {
                ++ans;
            }
            else if (ans > unmap[tasks[i]] + space) {
                ++ans;
            }
            else {
                ans += (ll)(unmap[tasks[i]] + space - ans + 1);
            }
            unmap[tasks[i]] = ans;
        }
        return ans;
    }
};