class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = (int)garbage.size();
        vector<vector<int>> A(n, vector<int>(3));
        vector<int> lastPos(3, -1);
        for (int i = 0; i < n; ++i) {
            for (auto& ch : garbage[i]) {
                if (ch == 'M') {
                    ++A[i][0];
                }
                else if (ch == 'G') {
                    ++A[i][1];
                }
                else {++A[i][2];}
            }
        }
        int sum = 0;
        int lastIndex;
        // m,g,x
        for (int k = 0; k <= 2; ++k) {
            lastIndex = -1;
            for (int i = n-1; i>=0; --i) {
                if (A[i][k] > 0) {
                    lastIndex = i;
                    break;
                }
            }
            if (lastIndex != -1) {
                for (int i = 0; i <= lastIndex; ++i) {
                    if (i != lastIndex) {
                        sum += travel[i];

                    }
                    if (A[i][k] > 0) {
                        sum += A[i][k];
                    }
                }
            }
        }
        return sum;
    }
};