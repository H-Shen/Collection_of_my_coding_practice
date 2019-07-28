class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        auto cmp = [](int *a, int *b, const int &len) {
            for (int i = 0; i < len; ++i) {
                if (a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        };

        const int MAXN = 26;
        int cnt[MAXN] = {0};
        int currCnt[MAXN] = {0};

        for (const auto &ch : s1) {
            ++cnt[ch - 'a'];
        }

        int len1 = static_cast<int>(s1.size());
        int len2 = static_cast<int>(s2.size());

        if (len2 < len1) {
            return false;
        }

        int startPos = 0;
        int endPos = len1 - 1;
        for (startPos = 0; startPos <= endPos; ++startPos) {
            ++currCnt[s2[startPos] - 'a'];
        }
        if (cmp(currCnt, cnt, MAXN)) {
            return true;
        }
        startPos = 0;

        while (endPos < len2) {
            --currCnt[s2[startPos] - 'a'];
            ++startPos;
            ++endPos;
            if (endPos < len2) {
                ++currCnt[s2[endPos] - 'a'];
            }

            //compare
            if (cmp(currCnt, cnt, MAXN)) {
                return true;
            }
        }
        return false;
    }
};