class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {

        vector<vector<int> > answer;
        string tmp;

        if (s.empty()) {
            return answer;
        }

        struct Pos {
            int startPos;
            int endPos;
            Pos(int a, int b) : startPos(a), endPos(b) {}
        };

        vector<Pos> res;
        char lastChar = s[0];
        tmp = lastChar;
        int len = static_cast<int>(s.size());
        int i;
        int startPos = 0;
        int endPos = 0;

        for (i = 1; i < len; ++i) {
            if (s[i] == lastChar) {
                tmp += s[i];
                ++endPos;
            } else {
                if (endPos - startPos + 1 >= 3) {
                    res.emplace_back(Pos(startPos, endPos));
                }
                tmp = s[i];
                lastChar = s[i];
                startPos = i;
                endPos = startPos;
            }
        }
        if (!tmp.empty()) {
            if (endPos - startPos + 1 >= 3) {
                res.emplace_back(Pos(startPos, endPos));
            }
        }

        sort(res.begin(), res.end(), [](const Pos &a, const Pos &b) {
            return (a.startPos < b.startPos);
        });

        answer.resize(res.size());
        len = static_cast<int>(answer.size());
        for (i = 0; i < len; ++i) {
            answer[i] = {res[i].startPos, res[i].endPos};
        }
        return answer;
    }
};