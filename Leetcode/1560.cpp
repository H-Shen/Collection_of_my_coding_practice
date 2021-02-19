class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> freq(n + 1, 0);
        int m = (int)rounds.size();
        int curr = rounds.front();
        int end;
        ++freq.at(curr);
        for (int i = 1; i < m; ++i) {
            while (curr != rounds.at(i)) {
                ++curr;
                if (curr > n) {
                    curr = 1; 
                }
                ++freq.at(curr);
            }
        }
        int maxFreq = *max_element(freq.begin(), freq.end());
        vector<int> result;
        for (int i = 1; i <= n; ++i) {
            if (freq.at(i) == maxFreq) result.emplace_back(i);
        }
        return result;
    }
};