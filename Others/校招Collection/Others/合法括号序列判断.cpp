// https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4

class Parenthesis {
public:
    bool chkParenthesis(string s, int n) {
        // write code here
        int len = n;
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