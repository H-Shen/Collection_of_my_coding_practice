class Solution {
public:
    unordered_set<int> unset;
    void dfs(string cur, int high) {
        int temp;
        try {
            temp = stoi(cur);
        } catch (...) {
            return;
        }
        if (temp > high || unset.find(temp) != unset.end() ) {
            return;
        }
        unset.insert(temp);
        
        char ch = cur.back();
        char new_ch;
        // Case 1:
        new_ch = ch + 1;
        if (new_ch >= '0' && new_ch <= '9') {
            dfs(cur + new_ch, high);
        }
        // Case 2:
        new_ch = ch - 1;
        if (new_ch >= '0' && new_ch <= '9') {
            dfs(cur + new_ch, high);
        }
    }
    vector<int> countSteppingNumbers(int low, int high) {
        vector<int> ans;
        for (char ch = '0'; ch <= '9'; ++ch) {
            dfs(string() + ch, high);
        }
        for (const auto &i : unset) {
            if (i >= low) {
                ans.emplace_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};