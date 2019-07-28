inline
bool isPalindrome(const string &A, const int len) {
    for (int i = 0, j = len - 1; i < j; ++i, --j) {
        if (A[i] != A[j]) {
            return false;
        }
    }
    return true;
}

class Palindrome {
public:
    string addToPalindrome(string A, int n) {
        string res, tmp;
        int len = n;

        for (int i = 0; i < n; ++i) {
            res = A[i] + res;
            tmp = A + res;
            ++len;
            if (isPalindrome(tmp, len)) {
                return res;
            }
        }

        return "";
    }
};