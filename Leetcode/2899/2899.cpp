class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        deque<int> nums;
        int counter = 0;
        int n = (int)words.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (words[i] == "prev") {
                ++counter;
                if (counter > (int)nums.size()) {
                    ans.emplace_back(-1);
                }
                else {
                    ans.emplace_back(nums[counter-1]);
                }
            }
            else {
                counter = 0;
                nums.push_front(stoi(words[i]));
            }
        }
        return ans;
    }
};