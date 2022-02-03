class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int l = 0, r = n-1;
        int mid;
        while (l <= r) {
            mid = l + ((r-l) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};