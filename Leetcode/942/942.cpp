class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = (int)s.size();
        deque<int> dq(n+1);
        iota(dq.begin(), dq.end(), 0);
        vector<int> ans;
        for (auto& ch : s) {
            if (ch == 'I') {
                ans.emplace_back(dq.front());
                dq.pop_front();
            }
            else {
                ans.emplace_back(dq.back());
                dq.pop_back();
            }
        }
        ans.emplace_back(dq.front());
        return ans;
    }
};