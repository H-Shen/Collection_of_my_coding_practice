class Solution {
public:
    string truncateSentence(string s, int k) {
        vector<string> v;
        istringstream iss(s);
        string temp;
        do {
            iss >> temp;
            v.emplace_back(temp);
        } while (iss);
        v.pop_back();
        string result;
        for (int i = 0; i < k; ++i) {
            if (i > 0) {
                result += ' ' + v.at(i);
            } else {
                result += v.at(i);
            }
        }
        return result;
    }
};