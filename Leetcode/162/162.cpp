class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = static_cast<int>(nums.size()) - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums.at(mid) < nums.at(mid + 1)) {
                start = mid;
            } else {
                end = mid;
            }
        }
        return (nums.at(start) > nums.at(end)) ? start : end;
    }
};