class Solution {
public:
    bool isPalindrome(int A) {
        if (A < 0) {
            return false;
        }
        if (A % 10 == 0 && A != 0) {
            return false;
        }
        decltype(A) A_rev{0};
        while (A > A_rev) {
            A_rev = A_rev * 10 + A % 10;
            A /= 10;
        }
        return (A == A_rev || A == A_rev / 10);
    }
};
