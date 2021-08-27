class Solution {
public:
    int numSplits(string s) {
        if (s.size() <= 1) return 0;
        deque<char> l, r;
        int ans = 0;
        int n = (int)s.size();
        l.push_back(s[0]);
        for (int i = 1; i < n; ++i) {
            r.push_back(s[i]);
        }
        unordered_map<char,int> unmap_l, unmap_r;
        for (const auto &i : l) ++unmap_l[i];
        for (const auto &i : r) ++unmap_r[i];
        char ch;
        while (!r.empty()) {
            if (unmap_l.size() == unmap_r.size()) {
                ++ans;
            }
            ch = r.front();
            l.push_back(ch);
            r.pop_front();
            ++unmap_l[ch];
            --unmap_r[ch];
            if (unmap_r[ch] == 0) unmap_r.erase(ch);
        }
        return ans;
    }
};