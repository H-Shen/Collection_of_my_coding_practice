class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = (int)s.size();
        for (const auto &i : shift) {
            if (i[0] == 1) {
                rotate(s.rbegin(), s.rbegin() + (i[1] % n), s.rend());
            } else {
                rotate(s.begin(), s.begin() + (i[1] % n), s.end());
            }
        }
        return s;
    }
};