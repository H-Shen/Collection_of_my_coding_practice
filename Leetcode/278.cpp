// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1) return 1;
        int l = 1, r = n, mid;
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            bool f1 = isBadVersion(mid);
            bool f2 = isBadVersion(mid + 1);
            if (f1 && f2) {
                r = mid - 1;
            }
            else if (!f1 && !f2) {
                l = mid + 1; 
            }
            else {
                return mid + 1;
            }
        }
        return r + 1;
    }
};