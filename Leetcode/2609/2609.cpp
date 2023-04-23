class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int n = (int)s.size();
        if (n & 1) ++n;
        n >= 1;
        deque<char> dq;
        for (int i = 0; i < n; ++i) {
            dq.push_back('0');
        }
        for (int i = 0; i < n; ++i) {
            dq.push_back('1');
        }
        while (!dq.empty()) {
            string sub(dq.begin(),dq.end());
            if (s.find(sub) != string::npos) {
                return (int)dq.size();
            }
            dq.pop_front();
            dq.pop_back();
        }
        return 0;
    }
};