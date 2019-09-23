// https://open.kattis.com/problems/apples
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int R, C;
    scanf("%d %d", &R, &C);
    getchar();
    vector<vector<char> > A(R, vector<char>(C));
    for (auto &i : A) {
        for (auto &j : i) {
            scanf("%c", &j);
        }
        getchar();
    }

    for (int col = 0; col < C; ++col) {
        vector<int> obstaclesPosition = {-1};
        for (int row = 0; row < R; ++row) {
            if (A.at(row).at(col) == '#') {
                obstaclesPosition.emplace_back(row);
            }
        }
        obstaclesPosition.emplace_back(R);
        int length = static_cast<int>(obstaclesPosition.size());
        int counterOfApples;
        for (int i = 0; i < length - 1; ++i) {
            if (obstaclesPosition.at(i + 1) - obstaclesPosition.at(i) <= 1) {
                continue;
            }

            counterOfApples = 0;
            // count the apples, erase the apples in a column
            for (int j = obstaclesPosition.at(i) + 1; j <= obstaclesPosition.at(i + 1) - 1; ++j) {
                if (A.at(j).at(col) == 'a') {
                    ++counterOfApples;
                    A.at(j).at(col) = '.';
                }
            }
            // re-allocate the apples in a column
            for (int j = obstaclesPosition.at(i + 1) - 1; counterOfApples > 0; --counterOfApples, --j) {
                A.at(j).at(col) = 'a';
            }
        }
    }
    // output
    for (const auto &i : A) {
        for (const auto &j : i) {
            printf("%c", j);
        }
        putchar('\n');
    }

    return 0;
}
