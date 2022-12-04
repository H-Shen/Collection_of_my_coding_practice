using ll = long long;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        deque<int> dq(skill.begin(),skill.end());
        ll ans = 0;
        ll sum = -1;
        while (!dq.empty()) {
            if (sum == -1) {
                sum = dq.front() + dq.back();
                ans += dq.front() * dq.back();
                dq.pop_front();
                dq.pop_back();
                continue;
            }
            if ((ll)dq.front() + dq.back() != sum) {
                return -1;
            }
                ans += (ll)dq.front() * dq.back();
                dq.pop_front();
                dq.pop_back();
        }
        return ans;
    }
};