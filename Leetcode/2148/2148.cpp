class Solution {
public:
    int countElements(vector<int>& nums) {
        deque<int> A(nums.begin(),nums.end());
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(),A.end()),A.end());
        if (A.size() <= 2) return 0;
        A.pop_front();
        A.pop_back();
        unordered_set<int> unset(A.begin(),A.end());
        int counter = 0;
        for (auto&i : nums) {
            if (unset.count(i) > 0) ++counter;
        }
        return counter;
    }
};