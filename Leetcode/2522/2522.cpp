class Solution {
public:
    inline
    bool equal(const string &a, int i, int j, const string &b, int x, int y) {
        int aLength = j-i+1;
        int bLength = y-x+1;
        if (aLength != bLength) return false;
        for (; i <= j; ++i, ++x) {
            if (a[i] != b[x]) {
                return false;
            }
        }
        return true;
    }
    inline
    bool smaller(const string &a, int i, int j, const string &b, int x, int y) {
        int aLength = j-i+1;
        int bLength = y-x+1;
        if (aLength < bLength) return true;
        else if (aLength > bLength) return false;
        for (; i <= j; ++i, ++x) {
            if (a[i] > b[x]) {
                return false;
            }
            else if (a[i] < b[x]) {
                return true;
            }
        }
        return false;
    }
    int minimumPartition(string s, int k) {
        deque<char> dq(s.begin(),s.end());
        string kstr = to_string(k);
        string str;
        int cnt = 0;
        kstr = to_string(k);
        while (!dq.empty()) {
            str.push_back(dq.front());
            if (smaller(str, 0, (int)str.size()-1, kstr, 0, (int)kstr.size()-1) || equal(str, 0, (int)str.size()-1, kstr, 0, (int)kstr.size()-1)) {
                dq.pop_front();
            }
            else {
                str.pop_back();
                if (str.empty()) {
                    return -1;
                }
                else {
                    ++cnt;
                    str.clear();
                }
            }
        }
        if (!str.empty()) {
            ++cnt;
        }
        return cnt;
    }
};