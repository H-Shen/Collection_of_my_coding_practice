class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = (int)s.size();
        if (n <= 1) {
            return 0;
        }
        int cnt = 0;
        bool flag;
        while (true) {
            flag = false;
            for (int i = 0; i < n; ) {
                if (s[i] == '0') {
                    if (i+1 < n && s[i+1] == '1') {
                        s[i] = '1';
                        s[i+1] = '0';
                        flag = true;
                        i += 2;
                    }
                    else {
                        ++i;
                    }
                }
                else {
                    ++i;
                }
            }
            if (!flag) {
                break;
            }
            else {
                ++cnt;
            }
        }
        return cnt;
    }
};