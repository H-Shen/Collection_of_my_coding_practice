class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int ans = 0;
        string s, sRev;
        int length;
        int pos;
        while (!words.empty()) {
            s = words.front();
            sRev = s;
            reverse(sRev.begin(),sRev.end());
            length = (int)words.size();
            pos = -1;
            for (int i = 1; i < length; ++i) {
                if (words[i] == sRev) {
                    pos = i;
                    break;
                }
            }
            if (pos != -1) {
                words.erase(words.begin() + pos);
                ++ans;
            }
            words.erase(words.begin());
        }
        return ans;
    }
};