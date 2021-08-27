using ll = long long;

class Solution {
public:
    bool isArmstrong(int n) {
        ll nCopy = n;
        ll counter = 0;
        while (nCopy > 0) {
            ++counter;
            nCopy /= 10;
        }
        nCopy = n;
        ll sum = 0;
        while (nCopy > 0) {
            sum += (ll)pow(nCopy % 10, counter);
            nCopy /= 10;
        }
        return sum == (ll)n;
    }
};