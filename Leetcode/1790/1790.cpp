class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        if (n1 != n2) return false;
        vector<int> vec;
        for (int i = 0; i < n1; ++i) {
            if (s1[i] != s2[i]) {
                vec.emplace_back(i);
                if (vec.size() > 2) return false;
            }
        }
        if (vec.empty()) return true;
        if (vec.size() != 2) return false;
        int idx0 = vec[0];
        int idx1 = vec[1];
        if (s1[idx0] == s2[idx1] && s1[idx1] == s2[idx0]) return true;
        return false;
    }
};