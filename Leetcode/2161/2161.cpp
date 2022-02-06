class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = (int)nums.size();
        int counter = 0;
        deque<pair<int,int>> dq1, dq3;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < pivot) {
                dq1.emplace_back(i,nums[i]);
            }
            else if (nums[i] == pivot) {
                ++counter;
            }
            else {
                dq3.emplace_back(i,nums[i]);
            }
        }
        sort(dq1.begin(),dq1.end(),[](const auto&l, const auto&r){
            return l.first < r.first;
        });
        sort(dq3.begin(),dq3.end(),[](const auto&l, const auto&r){
            return l.first < r.first;
        });
        vector<int> ans(n);
        int index = 0;
        for (auto&i : dq1) {
            ans[index++] = i.second;
        }
        for (int j = 0; j < counter; ++j) {
            ans[index++] = pivot;
        }
        for (auto&i : dq3) {
            ans[index++] = i.second;
        }
        return ans;
    }
};