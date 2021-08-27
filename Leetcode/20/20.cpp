class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        char cmp;
        stack<char> A;
        for (int i = 0; i < len; i++) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '(')
                A.push(s[i]);
            else {
                if (A.empty())
                    return false;
                else {
                    cmp = A.top();
                    if ((s[i] == ')' && cmp != '(') || (s[i] == '}' && cmp != '{') || (s[i] == ']' && cmp != '['))
                        return false;
                    A.pop();
                }
            }
            if (i == len - 1 && !A.empty())
                return false;
        }
        return true;
    }
};