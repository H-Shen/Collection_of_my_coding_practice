class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if (unordered_set<char>(suits.begin(),suits.end()).size() == 1) {
            return "Flush";
        }
        int n = 5;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (suits[i] != suits[j] && suits[j] != suits[k] && suits[i] != suits[k] &&
                        ranks[i] == ranks[j] && ranks[j] == ranks[k]) {
                        return "Three of a Kind";
                    }
                }
            }
        }
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (suits[i] != suits[j] && 
                    ranks[i] == ranks[j]) {
                    return "Pair";
                }
            }
        }
        return "High Card";
    }
};