struct myHashFunc {
    size_t operator()(const pair<int,int> &o) const {
        return hash<int>()(o.first)^hash<int>()(o.second);
    }  
};
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        unordered_map<pair<int,int>,char,myHashFunc> unmap;
        int i = 0, j = 0;
        int n = (int)s.size();
        int counter;
        int index = 0;
        bool flag = false;
        while (true) {
            for (counter = 1; counter <= numRows; ++counter) {
                unmap[{i,j}] = s[index];
                ++i;
                ++index;
                if (index >= n) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            --i;
            --index;
            for (counter = 1; counter <= numRows-1; ++counter) {
                unmap[{i,j}] = s[index];
                --i;
                ++j;
                ++index;
                if (index >= n) {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        vector<pair<pair<int,int>, char> > v(unmap.size());
        auto iter = v.begin();
        for (const auto &[i,j] : unmap) {
            iter->first.first = i.first;
            iter->first.second = i.second;
            iter->second = j;
            ++iter;
        }
        sort(v.begin(),v.end(),[](const auto &l, const auto &r){
            return l.first < r.first;
        });
        string ans;
        for (const auto &[i,j] : v) {
            ans.push_back(j);
        }
        return ans;
    }
};