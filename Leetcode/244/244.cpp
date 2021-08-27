class WordDistance {
private:
    unordered_map<string, vector<int> > unmap;
    int shortestDist(const vector<int> &v1, const vector<int> &v2) {
        int n1 = (int)v1.size();
        int n2 = (int)v2.size();
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n1; ++i) {
            if (v1[i] < v2.front()) {
                ans = min(ans, v2.front() - v1[i]);
            }
            else if (v1[i] > v2.back()) {
                ans = min(ans, v1[i] - v2.back());
            }
            else {
                auto iter1 = lower_bound(v2.begin(), v2.end(), v1[i]);
                auto iter2 = prev(iter1, 1);
                ans = min(ans, abs(*iter1 - v1[i]));
                ans = min(ans, abs(*iter2 - v1[i]));
            }
        }
        return ans;
    }
public:
    WordDistance(vector<string>& wordsDict) {
        int n = (int)wordsDict.size();
        for (int i = 0; i < n; ++i) {
            unmap[wordsDict[i]].emplace_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto v1 = unmap[word1];
        auto v2 = unmap[word2];
        if (v1.size() > v2.size()) {
            return shortestDist(v2, v1);
        }
        return shortestDist(v1, v2);
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */