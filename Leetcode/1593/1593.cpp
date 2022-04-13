class Solution {
public:
    int counter;
    void dfs(string&s, int currentIndex, unordered_set<string> vis) {
        if (currentIndex == (int)s.size()) {
            counter = max(counter, (int)vis.size());
            return;
        }
        // prune
        if ((int)s.size() - currentIndex + (int)vis.size() < counter) {
            return;
        }
        string str;
        for (int i = currentIndex; i < (int)s.size(); ++i) {
            str.push_back(s[i]);
            if (vis.count(str) == 0) {
                vis.insert(str);
                dfs(s, i + 1, vis);
                vis.erase(str);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = (int)s.size();
        counter = 0;
        string str;
        unordered_set<string> vis;
        for (int i = 0; i < n; ++i) {
            str.push_back(s[i]);
            vis.insert(str);
            dfs(s, i+1, vis);
            vis.erase(str);
        }
        return counter;
    }
};