class Solution {
public:
    string capitalizeTitle(string title) {
        istringstream iss(title);
        string str;
        vector<string> vec;
        do {
            iss >> str;
            vec.emplace_back(str);
        } while (iss);
        vec.pop_back();
        for (auto&i : vec) {
            if (i.size() <= 2) {
                for (auto &j : i) {
                    j = tolower(j);
                }
            }
            else {
                i[0] = toupper(i[0]);
                for (size_t j = 1; j != i.size(); ++j) {
                    i[j] = tolower(i[j]);
                }
            }
        }
        string result;
        bool first = true;
        for (auto&i : vec) {
            if (first) {
                first = false;
            }
            else {
                result.push_back(' ');
            }
            result += i;
        }
        return result;
    }
};