class Solution {
public:
    int bestClosingTime(string customers) {
        // j:
        // N: 1 => preLeft[j-1]
        // Y: 1 => preRight[j] 
        // j >= 0 && j <= n
        int n = (int)customers.size();
        vector<int> preLeft(n);
        preLeft[0] = (customers[0] == 'N' ) ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            preLeft[i] = preLeft[i-1] + ((customers[i] == 'N') ? 1 : 0);
        }
        vector<int> preRight(n);
        preRight[n-1] = (customers[n-1] == 'Y') ? 1 : 0;
        for (int i = n-2; i >= 0; --i) {
            preRight[i] = preRight[i+1] + ((customers[i] == 'Y') ? 1 : 0);
        }
        int minPenalty = numeric_limits<int>::max();
        int currentPenalty;
        for (int j = 0; j <= n; ++j) {
            if (j == 0) {
                currentPenalty = preRight[0];
            } else if (j == n) {
                currentPenalty = preLeft[n-1];
            } else {
                currentPenalty = preLeft[j-1] + preRight[j];
            }
            minPenalty = min(minPenalty, currentPenalty);
        }
        for (int j = 0; j <= n; ++j) {
            if (j == 0) {
                currentPenalty = preRight[0];
            } else if (j == n) {
                currentPenalty = preLeft[n-1];
            } else {
                currentPenalty = preLeft[j-1] + preRight[j];
            }
            if (currentPenalty == minPenalty) {
                return j;
            }
        }
        return -1;
    }
};