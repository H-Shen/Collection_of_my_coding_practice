class Solution {
public:
    bool rotateString(string A, string B) {

        if (A.empty() && B.empty())
            return true;

        unordered_set <string> Dict;
        bool res(true);
        string A_copy(A);
        for (size_t i = 0; i != A.size(); ++i) {
            rotate(A.begin(), A.begin() + i , A.end());
            Dict.insert(A);
            A = A_copy;
        }

        return (Dict.find(B) != Dict.end());
    }
};