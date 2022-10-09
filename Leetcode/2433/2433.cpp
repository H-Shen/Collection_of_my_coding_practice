class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = (int)pref.size();
        vector<int> ans(n);
        for (int i = n-1; i >= 0; --i) {
            if (i == 0) {
                ans[i] = pref[i];
            }
            else {
                ans[i] = pref[i] ^ pref[i-1];
            }
        }
        return ans;
    }
};