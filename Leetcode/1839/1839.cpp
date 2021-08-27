class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<pair<char,int> > vec;
        int counter = 0;
        char ch = 0;
        int n = (int)word.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ch = word[i];
                counter = 1;
                continue;
            }
            if (word[i] == ch) {
                ++counter;
            } else {
                vec.emplace_back(ch, counter);
                ch = word[i];
                counter = 1;
            }
        }
        if (counter > 0) {
            vec.emplace_back(ch, counter);
        }
        int result = 0;
        if (vec.size() < 4) {
            result = 0;
        }
        else {
            int m = (int)vec.size();
            for (int i = 0; i < m - 4; ++i) {
                if (vec[i].first == 'a' && vec[i+1].first == 'e' && vec[i+2].first == 'i' && vec[i+3].first == 'o' && vec[i+4].first == 'u') {
                    result = max(result, vec[i].second+vec[i+1].second+vec[i+2].second+vec[i+3].second+vec[i+4].second);
                }
            }
        }
        return result;
    }
};