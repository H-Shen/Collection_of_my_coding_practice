class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if (nums.empty()) return 0;
        deque<int> dq(nums.begin(),nums.end());
        int counter = 0;
        while (!dq.empty()) {
            if (dq.size() == 1) {
                ++counter;
                dq.pop_front();
                continue;
            }
            if (dq[0] == dq[1]) {
                dq.pop_front();
                ++counter;
            }
            else {
                dq.pop_front();
                dq.pop_front();
            }
        }
        return counter;
    }
};