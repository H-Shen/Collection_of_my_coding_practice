class Solution {
public:
    vector<string> letterCombinations(string digits) {

        auto mul = [](const vector<string> &a, const vector<string> &b) {
            vector<string> res(a.size() * b.size());
            size_t pos = 0;
            for (const auto &i : a) {
                for (const auto &j : b) {
                    res[pos++] = i + j;
                }
            }
            return res;
        };

        unordered_map<int, vector<string> > A;
        A[2] = {"a", "b", "c"};
        A[3] = {"d", "e", "f"};
        A[4] = {"g", "h", "i"};
        A[5] = {"j", "k", "l"};
        A[6] = {"m", "n", "o"};
        A[7] = {"p", "q", "r", "s"};
        A[8] = {"t", "u", "v"};
        A[9] = {"w", "x", "y", "z"};

        vector<string> res;
        int tmp;
        for (const auto &i : digits) {
            tmp = i - '0';
            if (A.find(tmp) != A.end()) {
                if (res.empty()) {
                    res = A[tmp];
                } else {
                    res = mul(res, A[tmp]);
                }
            } else {
                return vector<string>();
            }
        }
        return res;
    }
};