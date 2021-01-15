class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_set<string> namesSet;
        unordered_map<string, int> stats;
        vector<string> result;
        string temp;
        for (const auto &i : names) {
            if (stats.find(i) == stats.end()) {
                stats[i] = 0;
                namesSet.insert(i);
                result.emplace_back(i);
            } else {
                while (true) {
                    ++stats[i];
                    temp = i + "(" + to_string(stats[i]) + ")";
                    if (namesSet.find(temp) == namesSet.end()) {
                        namesSet.insert(temp);
                        result.emplace_back(temp);
                        stats[temp] = 0;
                        break;
                    }
                }
            }
        }
        return result;
    }
};