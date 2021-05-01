class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        istringstream iss(text);
        string s;
        int index = 0;
        vector<pair<string, int> > v;
        do {
            iss >> s;
            v.emplace_back(s, index);
            ++index;
        } while (iss);
        v.pop_back();
        sort(v.begin(), v.end(), [](const auto &l, const auto &r){
            if (l.first.size() == r.first.size()) {
                return l.second < r.second;
            }
            return l.first.size() < r.first.size();
        });
        string result;
        for (size_t i = 0; i != v.size(); ++i) {
            if (i == 0) {
                result += v[i].first;
                result[0] = toupper(result[0]);
            } else {
                result.push_back(' ');
                result += v[i].first;
            }
        }
        return result;
    }
};