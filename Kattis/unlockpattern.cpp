// https://open.kattis.com/problems/unlockpattern

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

double distance(const pair<int, int> & a, const pair<int, int> & b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                        (a.second - b.second) * (a.second - b.second));
}

int main() {

    ios_base::sync_with_stdio(false);
    unordered_map <int, pair<int, int> > A;
    int val;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> val;
            A[val] = {i, j};
        }
    }

    double s = 0.0;
    for (int i = 1; i <= 8; ++i) {
        s += distance(A[i], A[i + 1]);
    }
    printf("%.6f\n", s);

    return 0;
}
