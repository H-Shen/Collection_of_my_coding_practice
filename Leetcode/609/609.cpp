class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string> > unmap;    // content->list of paths
        string s, path;
        int n;
        for (const auto &i : paths) {
            vector<string> v;
            istringstream iss(i);
            s;
            do {
                iss >> s;
                v.emplace_back(s);
            } while (iss);
            v.pop_back();
            path = v[0];
            n = (int)v.size();
            if (path.back() != '/') {
                path.push_back('/');
            }
            for (int j = 1; j < n; ++j) {
                string filename, content;
                int m = (int)v[j].size();
                int k;
                for (k = 0; v[j][k] != '('; ++k) {
                    filename.push_back(v[j][k]);
                }
                ++k;
                for (; v[j][k] != ')'; ++k) {
                    content.push_back(v[j][k]);
                }
                unmap[content].emplace_back(path+filename);
            }
        }
        vector<vector<string>> ans;
        for (const auto &[k,vList] : unmap) {
            // duplicate files only
            if (vList.size() > 1) {
                ans.emplace_back(vList);
            }
        }
        return ans;
    }
};