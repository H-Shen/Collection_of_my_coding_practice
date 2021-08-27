string_view sub_string(
  string_view s, 
  size_t p, 
  size_t n = string_view::npos) {
  return s.substr(p, n);
}

class Solution {
public:
    int longestRepeatingSubstring(string s) {
        // enumerate all substrings
        int n = (int)s.size();
        unordered_map<string_view,pair<int,int> > unmap; // hash->(freq, maxLength)
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                auto sv = sub_string(s, i, j-i+1);
                auto &val = unmap[sv];
                ++val.first;
                val.second = max(val.second,j-i+1);
            }
        }
        int ans = 0;
        for (const auto &[k,v] : unmap) {
            if (v.first > 1) {
                ans = max(ans, v.second);
            }
        }
        return ans;
    }
};