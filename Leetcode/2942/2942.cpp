class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> vec;
        int n = (int)words.size();
        for (int i = 0; i < n; ++i) {
            if (find(words[i].begin(),words[i].end(),x) != words[i].end()) vec.emplace_back(i);
        }
        return vec;
    }
};