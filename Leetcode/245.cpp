class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = (int)wordsDict.size();
        int shortestDist = numeric_limits<int>::max();
        if (word1 != word2) {
            vector<int> word1pos, word2pos;
            for (int i = 0; i < n; ++i) {
                if (wordsDict[i] == word1) {
                    word1pos.emplace_back(i);
                }
                if (wordsDict[i] == word2) {
                    word2pos.emplace_back(i);
                }
            }
            int dist;
            for (const auto &i : word1pos) {
                if (i < word2pos.front()) {
                    dist = abs(i-word2pos.front());
                    shortestDist = min(shortestDist, dist);
                }
                else if (i > word2pos.back()) {
                    dist = abs(i-word2pos.back());
                    shortestDist = min(shortestDist, dist);
                }
                else {
                    auto iter = lower_bound(word2pos.begin(), word2pos.end(), i);
                    int dist1 = abs(i-*iter);
                    --iter;
                    int dist2 = abs(i-*iter);
                    if (dist1 > dist2) {
                        dist = dist2;
                    } else {
                        dist = dist1;
                    }
                    shortestDist = min(shortestDist, dist);
                }
            }
        }
        else {
            vector<int> wordpos;
            for (int i = 0; i < n; ++i) {
                if (wordsDict[i] == word1) {
                    wordpos.emplace_back(i);
                }
            }
            int length = (int)wordpos.size();
            for (int i = 0; i < length - 1; ++i) {
                shortestDist = min(shortestDist, wordpos[i+1]-wordpos[i]);
            }
        }
        return shortestDist;
    }
};