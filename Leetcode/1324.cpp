class Solution {
public:
    vector<string> printVertically(string s) {
        istringstream iss(s);
        string str;
        vector<string> v;
        do {
            iss >> str;
            v.emplace_back(str);
        } while (iss);
        v.pop_back();
        size_t maxLength = max_element(v.begin(),v.end(),[](const auto &l,const auto&r){
            return l.size() < r.size();
        })->size();
        vector<vector<char> > vec(maxLength, vector<char>(v.size(), ' '));
        for (size_t i = 0; i != v.size(); ++i) {
            for (size_t j = 0; j != v.at(i).size(); ++j) {
                vec.at(j).at(i) = v.at(i).at(j);
            }
        }
        vector<string> ans;
        for (const auto &i : vec) {
            string temp(i.begin(),i.end());
            while (temp.size() > 1 && temp.back() == ' ') {
                temp.pop_back();
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};