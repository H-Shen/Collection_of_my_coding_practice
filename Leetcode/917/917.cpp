class Solution {
public:
    string reverseOnlyLetters(string S) {
        vector<char> A;
        for (const char &i : S) {
            if (isalpha(i)) {
                A.emplace_back(i);
            }
        }
        auto it = A.crbegin();
        for (char &i : S) {
            if (isalpha(i)) {
                i = *it;
                ++it;
            }
        }
        return S;
    }
};