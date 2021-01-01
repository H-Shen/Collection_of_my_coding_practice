class Solution {
public:
    vector<int> f(const string &s) {
        constexpr int MAXN = 300;
        vector<int> S(MAXN, -1);
        vector<int> A(s.size());
        int counter = 0;
        for (size_t i = 0; i != A.size(); ++i) {
            if (S.at(s.at(i)) == -1) {
                S.at(s.at(i)) = counter;
                A.at(i) = counter;
                ++counter;
            } else {
                A.at(i) = S.at(s.at(i));
            }
        }
        return A;
    }
    bool isIsomorphic(string s, string t) {
        return f(s) == f(t);
    }
};