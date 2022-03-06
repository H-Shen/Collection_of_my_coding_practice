class Solution {
public:
    struct Node {
        int first;
        int second;
        int third;
    };
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = (int)nums.size();
        vector<Node> vec(n);
        string temp;
        for (int i = 0; i < n; ++i) {
            vec[i].first = nums[i];
            vec[i].second = i;
            temp = to_string(nums[i]);
            for (auto& j : temp) {
                j = mapping[j - '0'] + '0';
            }
            vec[i].third = stoi(temp);
        }
        sort(vec.begin(),vec.end(),[&](const auto &l, const auto &r){
            if (l.third == r.third) {
                return l.second < r.second;
            }
            return l.third < r.third;
        });
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = vec[i].first;
        }
        return ans;
    }
};