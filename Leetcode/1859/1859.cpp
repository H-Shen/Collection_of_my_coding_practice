class Solution {
public:
    string sortSentence(string s) {
        string ans;
        istringstream iss(s);
        vector<string> vec;
        string temp;
        do {
            iss >> temp;
            vec.emplace_back(temp);
        } while (iss);
        vec.pop_back();
        vector<pair<string,int> > v;
        for (auto &i : vec) {
            int pos = i.back() - '0';
            i.pop_back();
            v.emplace_back(i, pos);
        }
        sort(v.begin(), v.end(), [](const auto &l, const auto &r){
            return l.second < r.second;
        });
        bool firstItem = true;
        for (const auto &i : v) {
            if (firstItem) {
                firstItem = false;
            } else {
                ans.push_back(' ');
            }
            ans += i.first;
        }
        return ans;
    }
};