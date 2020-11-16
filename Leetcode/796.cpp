class Solution {
public:
    // Booth's algorithm : O(s.size())
    int minimalRotation(string s) {
        s += s; // Concatenate string to it self to avoid modular arithmetic
        int length = (int)s.size();
        vector<int> f(length, -1);    // Failure function
        int k = 0;  // Least rotation of string found so far
        for (int j = 1, i; j < length; ++j) {
            char sj = s.at(j);
            i = f.at(j - k - 1);
            while (i != -1 && sj != s.at(k + i + 1)) {
                if (sj < s.at(k + i + 1)) {
                    k = j - i - 1;
                }
                i = f.at(i);
            }
            if (sj != s.at(k + i + 1)) {
                if (sj < s.at(k)) {
                    k = j;
                }
                f.at(j - k) = -1;
            } else {
                f.at(j - k) = i + 1;
            }
        }
        return k;
    }
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        rotate(A.begin(), A.begin() + minimalRotation(A), A.end());
        rotate(B.begin(), B.begin() + minimalRotation(B), B.end());
        return A == B;
    }
};