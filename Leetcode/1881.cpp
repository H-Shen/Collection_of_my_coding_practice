class Solution {
public:
    string maxValue(string n, int x) {
        int length = (int)n.size();
        char ch = x + '0';
        if (n[0] == '-') {
            string s;
            s.push_back('-');
            bool haveInserted = false;
            for (int i = 1; i < length; ++i) {
                if (!haveInserted && n[i] > ch) {
                    s.push_back(ch);
                    haveInserted = true;
                    s.push_back(n[i]);
                } else {
                    s.push_back(n[i]);
                }
            }
            if (!haveInserted) {
                s.push_back(ch);
            }
            return s;
        }
        else {
            string s;
            bool haveInserted = false;
            for (int i = 0; i < length; ++i) {
                if (!haveInserted && n[i] < ch) {
                    s.push_back(ch);
                    haveInserted = true;
                    s.push_back(n[i]);
                } else {
                    s.push_back(n[i]);
                }
            }
            if (!haveInserted) {
                s.push_back(ch);
            }
            return s;
        }
    }
};