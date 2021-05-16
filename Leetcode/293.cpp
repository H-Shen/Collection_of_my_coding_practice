class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        int n = (int)currentState.size();
        if (n == 1) {
            return ans;
        }
        for (int i = 0; i < n - 1; ++i) {
            if (currentState[i] == '+' && currentState[i+1] == '+') {
                currentState[i] = '-';
                currentState[i+1] = '-';
                ans.emplace_back(currentState);
                currentState[i] = '+';
                currentState[i+1] = '+';
            }
        }
        return ans;
    }
};