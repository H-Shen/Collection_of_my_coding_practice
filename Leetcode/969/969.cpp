class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> ans;
        // a variant of select-sort, choose the max value each time, flip it to the front, and then flip it to the sorted position
        for (int i = n-1; i >= 0; --i) {
            int pos = (int)(max_element(arr.begin(),arr.begin()+i+1) - arr.begin());
            // flip if it is not in the front of the array
            if (pos != 0) {
                ans.emplace_back(pos+1);
                reverse(arr.begin(),arr.begin()+pos+1);
            }
            ans.emplace_back(i+1);
            reverse(arr.begin(),arr.begin()+i+1);
        }
        return ans;
    }
};