// https://open.kattis.com/problems/conquestcampaign
//
#include <bits/stdc++.h>

using namespace std;

int counter = 0;
int day = 1;

inline static
void go(vector<vector<int> > &A, int i, int j, int val) {
    try {
        if (A.at(i - 1).at(j) == 0) {
            A.at(i - 1).at(j) = val;
            ++counter;
        }
    } catch (...) {}
    try {
        if (A.at(i + 1).at(j) == 0) {
            A.at(i + 1).at(j) = val;
            ++counter;
        }
    } catch (...) {}
    try {
        if (A.at(i).at(j - 1) == 0) {
            A.at(i).at(j - 1) = val;
            ++counter;
        }
    } catch (...) {}
    try {
        if (A.at(i).at(j + 1) == 0) {
            A.at(i).at(j + 1) = val;
            ++counter;
        }
    } catch (...) {}
}

int main() {

    int r, c, n, x, y;
    scanf("%d %d %d", &r, &c, &n);
    vector<vector<int> > A(r, vector<int>(c));
    while (n--) {
        scanf("%d %d", &x, &y);
        if (A.at(x - 1).at(y - 1) == 0) {
            A.at(x - 1).at(y - 1) = 1;
            ++counter;
        }
    }
    while (counter < r * c) {
        vector<pair<int, int> > temp;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (A.at(i).at(j) == day) {
                    temp.emplace_back(i, j);
                }
            }
        }
        ++day;
        for (const auto &i : temp) {
            go(A, i.first, i.second, day);
        }
    }
    printf("%d\n", day);

    return 0;
}
