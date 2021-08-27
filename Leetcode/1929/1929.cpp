class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res(nums.size() << 1);
        copy(nums.begin(),nums.end(),res.begin());
        copy(nums.begin(),nums.end(),res.begin()+nums.size());
        return res;
    }
};