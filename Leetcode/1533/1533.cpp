/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int length = reader.length();
        int left = 0;
        int right = length-1;
        int mid;
        int temp;
        while (true) {
            length = right - left + 1;
            if (length == 1) {
                return left;
            }
            mid = left + ((right-left) >> 1);
            if (length & 1) {
                temp = reader.compareSub(left,mid-1,mid+1,right);
                if (temp == 0) {
                    return mid;
                }
                else if (temp < 0) {
                    left = mid+1;
                }
                else {
                    right = mid-1;
                }
            }
            else {
                temp = reader.compareSub(left,mid,mid+1,right);
                if (temp == 0) {
                    break;
                }
                else if (temp < 0) {
                    left = mid+1;
                }
                else {
                    right = mid;
                }
            }
        }
        return -1;
    }
};