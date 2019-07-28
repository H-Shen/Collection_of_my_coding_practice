// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while (true) {
            if (low > high) {
                return -1;
            }
            int mid = low + (high - low) / 2;
            int key = guess(mid);
            if (key == -1) {
                high = mid - 1;
            } else if (key == 1) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
    }
};