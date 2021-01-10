class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result;
        result.resize(s.size());
        for (size_t i = 0; i != s.size(); ++i) {
            result.at(indices.at(i)) = s.at(i);
        }
        return result;
    }
};