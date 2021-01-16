class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.size() <= 2) return true;
        int n = (int)A.size();
        int inc = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (A.at(i) == A.at(i + 1)) {
                continue;
            }
            if (A.at(i) > A.at(i + 1)) {
                if (inc == 0) {
                    inc = 1;
                } else if (inc == -1) {
                    return false;
                }
            }
            else if (A.at(i) < A.at(i + 1)) {
                if (inc == 0) {
                    inc = -1;
                } else if (inc == 1) {
                    return false;
                }
            }
        }
        return true;
    }
};