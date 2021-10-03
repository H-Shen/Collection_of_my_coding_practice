class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int counter = 0;
        unordered_map<string_view,int> unmap;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            ++unmap[nums[i]];
        }
        int length = (int)target.size();
        string_view sv(target);
        for (int i = 1; i <= length-1; ++i) {
            if (unmap.find(sv.substr(0,i)) != unmap.end() && unmap.find(sv.substr(i,length-i)) != unmap.end()) {
                if (sv.substr(0,i) == sv.substr(i, length-i)) {
                    int temp = unmap[sv.substr(0,i)];
                    counter += temp*(temp-1);
                }
                else {
                    counter += unmap[sv.substr(0,i)]*unmap[sv.substr(i,length-i)];
                }
            }
        }
        return counter;
    }
};