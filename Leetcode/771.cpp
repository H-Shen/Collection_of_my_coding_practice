class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> A(J.begin(), J.end());
        int cnt = 0;
        for (const auto &i : S) {
            if (A.find(i) != A.end()) {
                ++cnt;
            }
        }
        return cnt;
    }
};