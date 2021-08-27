class Solution {
public:
    string getTime(int time) {
        int h = time / 60;
        int m = time % 60;
        string ret;
        if (h < 10) {
            ret.push_back('0');
        }
        ret += to_string(h);
        ret.push_back(':');
        if (m < 10) {
            ret.push_back('0');
        }
        ret += to_string(m);
        return ret;
    }
    string maximumTime(string time) {
        constexpr int MAXN = 24*60;
        string ans, s;
        bool haveAns;
        for (int i = MAXN - 1; i >= 0; --i) {
            s = getTime(i);
            haveAns = true;
            for (size_t j = 0; j != time.size(); ++j) {
                if (s[j] != time[j] && time[j] != '?') {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                return s;
            }
        } 
        return string();
    }
};