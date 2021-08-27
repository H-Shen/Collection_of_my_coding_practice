class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<int> v;
        istringstream iss(s);
        string temp;
        unordered_map<string, int> unmap;
        int id = 0;
        do {
            iss >> temp;
            if (unmap.find(temp) == unmap.end()) {
                unmap[temp] = id;
                v.emplace_back(id);
                ++id;
            } else {
                v.emplace_back(unmap[temp]);
            }
        } while (iss);
        v.pop_back();
        
        vector<int> v_;
        unordered_map<char, int> unmap_;
        id = 0;
        for (const char &ch : pattern) {
            if (unmap_.find(ch) == unmap_.end()) {
                unmap_[ch] = id;
                v_.emplace_back(id);
                ++id;
            } else {
                v_.emplace_back(unmap_[ch]);
            }
        }
        return v == v_;
    }
};