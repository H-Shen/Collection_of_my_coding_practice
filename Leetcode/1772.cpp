class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_map<string,pair<int,int>> unmap; // feature: (index, freq)
        int n = (int)features.size();
        for (int i = 0; i < n; ++i) {
            unmap[features[i]].first = i;
        }
        vector<string> parse;
        string temp;
        for (const auto &i : responses) {
            istringstream iss(i);
            vector<string>().swap(parse);
            do {
                iss >> temp;
                parse.emplace_back(temp);
            } while (iss);
            parse.pop_back();
            unordered_set<string> unset(parse.begin(),parse.end());
            for (const auto &j : unset) {
                if (unmap.find(j) != unmap.end()) {
                    ++unmap[j].second;
                }
            }
        }
        vector<pair<string, pair<int,int>>> vec(unmap.begin(),unmap.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (l.second.second == r.second.second) {
                return l.second.first < r.second.first;
            } 
            return l.second.second > r.second.second;
        });
        vector<string> ans(vec.size());
        for (size_t i = 0; i != ans.size(); ++i) {
            ans[i] = vec[i].first;
        }
        return ans;
    }
};