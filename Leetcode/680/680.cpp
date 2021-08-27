class Solution {
public:
    bool isPalindrome(const string &s) {
        int n = (int)s.size();
        int half = n >> 1;
        for (int i = 0; i < half; ++i) {
            if (s[i] != s[n-1-i]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        deque<char> dq(s.begin(),s.end());
        char ch;
        while (dq.size() > 1) {
            if (dq.front() == dq.back()) {
                dq.pop_front();
                dq.pop_back();
            }
            else {
                ch = dq.front();
                dq.pop_front();
                if (isPalindrome(string(dq.begin(),dq.end()))) {
                    return true;
                }
                dq.push_front(ch);
                dq.pop_back();
                if (isPalindrome(string(dq.begin(),dq.end()))) {
                    return true;
                }
                return false;
            }
        }
        return true;
    }
};