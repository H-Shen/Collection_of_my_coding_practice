class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {

        for (auto &&i : paragraph) {
            if (isupper(i)) {
                i = tolower(i);
            } else if (!isalpha(i)) {
                i = ' ';
            }
        }

        string word;
        vector<string> wordList;
        istringstream ss(paragraph);
        while (ss) {
            ss >> word;
            wordList.push_back(word);
        }
        wordList.pop_back();
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> A;
        for (const auto &i : wordList) {
            if (bannedSet.find(i) == bannedSet.end()) {
                ++A[i];
            }
        }
        int maxFreq = 0;
        for (const auto &it : A) {
            maxFreq = max(maxFreq, it.second);
        }
        string res;
        for (const auto &it : A) {
            if (it.second == maxFreq) {
                res = it.first;
            }
        }
        return res;
    }
};