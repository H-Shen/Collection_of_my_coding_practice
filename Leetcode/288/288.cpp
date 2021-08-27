class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string> > unmap;
    string getAbbr(const string &s) {
        if (s.size() <= 2) {
            return s;
        }
        string ans;
        ans.push_back(s.front());
        ans += to_string((int)s.size() - 2);
        ans.push_back(s.back());
        return ans;
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (const auto &i : dictionary) {
            unmap[getAbbr(i)].insert(i);
        }
    }
    
    bool isUnique(string word) {
        string abbr = getAbbr(word);
        if (unmap.find(abbr) == unmap.end()) {
            return true;
        }
        else if (unmap[abbr].find(word) != unmap[abbr].end() && unmap[abbr].size() == 1) {
            return true;
        }
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */