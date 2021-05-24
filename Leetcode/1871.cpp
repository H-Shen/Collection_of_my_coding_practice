class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // Corner case
        if (s.back() == '1') {
            return false;
        }
        vector<int> posOfZeroes;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                posOfZeroes.emplace_back(i);
            } 
        }
        queue<int> q;
        q.push(0);
        int lastCheck = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            lastCheck = max(lastCheck,u+minJump);   // update lastCheck
            int upperbound = min(u + maxJump, n - 1);
            auto iter = lower_bound(posOfZeroes.begin(),posOfZeroes.end(),lastCheck);
            for (;iter != posOfZeroes.end() && *iter <= upperbound; ++iter) {
                if (*iter == n-1) {
                    return true;
                }
                q.push(*iter);
            }
            lastCheck = upperbound;  // update lastCheck
            // which means we dont need to care about stuff before lastCheck anymore
        }
        return false;
    }
};