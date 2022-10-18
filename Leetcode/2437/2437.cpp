class Solution {
public:
    inline
    bool valid(const string& s) const {
        if (s[0] > '2') return false;
        if (s[0] == '2' && s[1] > '3') return false;
        if (s[3] > '5') return false;
        return true;
    }
    int countTime(string time) {
        string temp(5,':');
        bool flag;
        int cnt = 0;
        for (char a = '0'; a <= '9'; ++a) {
            for (char b = '0'; b <= '9'; ++b) {
                for (char c = '0'; c <= '9'; ++c) {
                    for (char d = '0'; d <= '9'; ++d) {
                        temp[0] = a;
                        temp[1] = b;
                        temp[3] = c;
                        temp[4] = d;
                        flag = true;
                        for (int i = 0; i < 5; ++i) {
                            if (time[i] != '?' && time[i] != temp[i]) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag && valid(temp)) {
                            ++cnt;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};