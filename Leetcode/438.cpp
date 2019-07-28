class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        auto checkInclusion = [](vector<int> &res, const string &s1, const string &s2) -> void {
            auto cmp = [](const int *a, const int *b, const int &len) -> bool {
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
                return;
            }

            int startPos = 0;
            int endPos = len1 - 1;
            for (startPos = 0; startPos <= endPos; ++startPos) {
                ++currCnt[s2[startPos] - 'a'];
            }
            startPos = 0;
            if (cmp(currCnt, cnt, MAXN)) {
                res.push_back(startPos);
            }

            while (endPos < len2) {
                --currCnt[s2[startPos] - 'a'];
                ++startPos;
                ++endPos;
                if (endPos < len2) {
                    ++currCnt[s2[endPos] - 'a'];
                }

                //compare
                if (cmp(currCnt, cnt, MAXN)) {
                    res.push_back(startPos);
                }
            }
        };

        vector<int> res;
        checkInclusion(res, p, s);
        return res;
    }
};