class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int n = (int)brackets.size();
        double s = 0.0;
        for (int i = 0; i < n; ++i) {
            if (brackets[i][0] > income) {
                if (i == 0) {
                    s += income * brackets[i][1] / 100.0;
                }
                else {
                    s += (income - brackets[i-1][0]) * brackets[i][1] / 100.0;
                }
                break;
            }
            if (i == 0) {
                s += brackets[i][0] * brackets[i][1] / 100.0;
            }
            else {
                s += (brackets[i][0] - brackets[i-1][0]) * brackets[i][1] / 100.0;
            }
        }
        return s;
    }
};