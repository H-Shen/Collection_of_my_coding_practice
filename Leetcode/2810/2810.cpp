class Solution {
public:
    string finalString(string s) {
        deque<char> dq;
        bool rev = false;
        for (const char &ch : s) {
            if (ch == 'i') rev = !rev;
            else {
                if (rev) dq.push_front(ch);
                else dq.push_back(ch);
            }
        }
        string ans(dq.begin(),dq.end());
        if (rev) reverse(ans.begin(),ans.end());
        return ans;
    }
};