class Solution {
public:
    string oddString(vector<string>& words) {
        int n = (int)words.size();
        int length = (int)words[0].size();
        vector<int> diff1;
        int freq1 = 0;
        vector<int> diff2;
        int freq2 = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> diff;
            for (int j = 0; j <= length-2; ++j) {
                diff.emplace_back(words[i][j+1] - words[i][j]);
            }
            if (i == 0) {
                swap(diff1, diff);
                ++freq1;
                continue;
            }
            if (diff == diff1) {
                ++freq1;
            }
            else {
                if (diff2.empty()) {
                    diff2 = diff;
                }
                ++freq2;
            }
        }
        if (freq1 != 1) {
            swap(diff1, diff2);
        }
        for (int i = 0; i < n; ++i) {
            vector<int> diff;
            for (int j = 0; j <= length-2; ++j) {
                diff.emplace_back(words[i][j+1] - words[i][j]);
            }
            if (diff == diff1) {
                return words[i];
            }
        }
        return string();
    }
};