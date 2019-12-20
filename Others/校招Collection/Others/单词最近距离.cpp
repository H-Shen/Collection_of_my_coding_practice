// https://www.nowcoder.com/practice/1a002eed40054042867eb1aa5b98fb11

#include <bits/stdc++.h>

using namespace std;

class Distance {
public:
    int getDistance(vector<string> article, int n, string x, string y) {

        vector<int> x_pos, y_pos;
        int i, j;
        int x_pos_len = 0, y_pos_len = 0;

        for (i = 0; i < n; i++) {
            if (article[i] == x) {
                x_pos.push_back(i);
                x_pos_len++;
            } else if (article[i] == y) {
                y_pos.push_back(i);
                y_pos_len++;
            }
        }

        int minAbsDiff = n + 5, currentAbsDiff = 0;
        for (i = 0; i < x_pos_len; i++) {
            if (x_pos[i] < y_pos[0]) {
                currentAbsDiff = y_pos[0] - x_pos[i];
            } else if (x_pos[i] > y_pos[y_pos_len - 1]) {
                currentAbsDiff = -y_pos[y_pos_len - 1] + x_pos[i];
            } else {
                for (j = 0; j < y_pos_len - 1; j++) {
                    if ((x_pos[i] - y_pos[j]) * (x_pos[i] - y_pos[j + 1]) < 0) {
                        currentAbsDiff = min(abs(x_pos[i] - y_pos[j]), abs(x_pos[i] - y_pos[j + 1]));
                        break;
                    }
                }
            }
            minAbsDiff = min(minAbsDiff, currentAbsDiff);
            if (minAbsDiff == 1)
                return minAbsDiff;
        }

        return minAbsDiff;
    }
};