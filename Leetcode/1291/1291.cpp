class Solution {
public:
    vector<int> f(int length) {
        constexpr int MAXN = 9;
        vector<int> res;
        vector<char> p(MAXN);
        iota(p.begin(), p.end(), '1');
        for (int i = 0, j = length - 1; j < MAXN; ++i, ++j) {
            res.emplace_back(stoi(string(p.begin() + i, p.begin() + i + length)));
        }
        return res;
    }
    vector<int> sequentialDigits(int low, int high) {
        int a = (int)to_string(low).size();
        int b = (int)to_string(high).size();
        vector<int> ans;
        for (int i = a; i <= b; ++i) {
            auto p = f(i);
            for (const auto &j : p) {
                if (j >= low && j <= high) {
                    ans.emplace_back(j);
                }
            }
        }
        return ans;
    }
};