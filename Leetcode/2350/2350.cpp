class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_map<int,int> freq;
        int n = (int)rolls.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ++freq[rolls[i]];
            if ((int)freq.size() == k) {
                ++ans;
                freq.clear();
            }
        }
        return ans+1;
    }
};