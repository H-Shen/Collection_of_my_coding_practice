class Solution {
public:
    int countOdds(int low, int high) {
        int a, b;
        if (low % 2 != 0 && high % 2 != 0) {
            a = (low-1)/2;
            b = (high-1)/2;
            return b-a+1;
        }
        else if (low % 2 != 0 && high % 2 == 0) {
            a = (low-1)/2;
            b = high/2;
            return (b-1)-a+1;
        }
        else if (low % 2 == 0 && high % 2 != 0) {
            return countOdds(low+1,high);
        }
        else {
            a = low/2;
            b = high/2;
            if (a==b) return 0;
            return countOdds(low+1,high);
        }
    }
};