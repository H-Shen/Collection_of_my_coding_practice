/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

constexpr int MAXN = 1e4-1;
constexpr int OUT_OF_RANGE = (int)(2LL<<31-1LL);

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = MAXN;
        int mid;
        int temp;
        while (left <= right) {
            mid = left + ((right-left) >> 1);
            temp = reader.get(mid);
            if (temp == OUT_OF_RANGE) {
                right = mid - 1;
            }
            else if (temp < target) {
                left = mid + 1;
            }
            else if (temp > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};