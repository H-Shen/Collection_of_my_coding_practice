class Solution {
public:
    int wordCount(const string& s) {
        bool inWord = false;
        int counter = 0;
        for (auto& ch : s) {
            if (isspace(ch)) {
                if (inWord) {
                    inWord = false;
                    ++counter;
                }
            }
            else {
                if (!inWord) {
                    inWord = true;
                }
            }
        }
        if (inWord) {
            ++counter;
        }
        return counter;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = (int)messages.size();
        unordered_map<string, int> unmap;
        for (int i = 0; i < n; ++i) {
            unmap[senders[i]] += wordCount(messages[i]);
        }
        vector<pair<string,int>> vec(unmap.begin(),unmap.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (l.second == r.second) {
                return l.first > r.first;
            }
            return l.second > r.second;
        });
        return vec[0].first;
    }
};