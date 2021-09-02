class Solution {
public:
    string join(const vector<string>& vec) {
        string str;
        if (!vec.empty()) {
            str += vec[0];
            for (size_t i = 1; i != vec.size(); ++i) {
                str.push_back(' ');
                str += vec[i];
            }
        }
        return str;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string_view> dict(dictionary.begin(),dictionary.end());
        vector<string> vec;
        istringstream iss(sentence);
        string temp;
        do {
            iss >> temp;
            vec.emplace_back(temp);
        } while (iss);
        vec.pop_back();
        for (auto &s : vec) {
            int length = (int)s.size();
            for (int i = 0; i < length; ++i) {
                string_view sv(s.data(), i+1);
                if (dict.find(sv) != dict.end()) {
                    while ((int)s.size() > i+1) {
                        s.pop_back();
                    }
                    break;
                }
            }
        }
        return join(vec);
    }
};