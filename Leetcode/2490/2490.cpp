class Solution {
public:
    bool isCircularSentence(string sentence) {
        istringstream iss(sentence);
        vector<string> vec;
        string temp;
        do {
            iss >> temp;
            vec.emplace_back(temp);
        } while (iss);
        vec.pop_back();
        int n = (int)vec.size();
        for (int i = 0; i < n-1; ++i) {
            if (vec[i].back() != vec[i+1].front()) {
                return false;
            }
        }
        if (vec.front().front() != vec.back().back()) {
            return false;
        }
        return true;
    }
};