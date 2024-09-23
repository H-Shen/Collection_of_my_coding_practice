#include <bits/stdc++.h>

using namespace std;

struct Pixel {
    int x;
    int y;
    int val;
};

int main() {
    int M, N, TOL, i, j;
    scanf("%d %d %d", &M, &N, &TOL);
    vector<vector<int> > A(N, vector<int>(M));
    unordered_map<int, int> freq;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            scanf("%d", &A[i][j]);
            ++freq[A[i][j]];
        }
    }
    vector<Pixel> res;
    Pixel tmp;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {

            try {
                if (abs(A.at(i).at(j) - A.at(i - 1).at(j)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i + 1).at(j)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i).at(j - 1)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i).at(j + 1)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i + 1).at(j + 1)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i + 1).at(j - 1)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i - 1).at(j + 1)) <= TOL)
                    continue;
            } catch (...) {}

            try {
                if (abs(A.at(i).at(j) - A.at(i - 1).at(j - 1)) <= TOL)
                    continue;
            } catch (...) {}

            if (freq[A.at(i).at(j)] == 1) {
                tmp.val = A.at(i).at(j);
                tmp.x = j;
                tmp.y = i;
                res.push_back(tmp);
            }
        }
    }
    if (res.empty()) {
        printf("Not Exist\n");
    } else if (res.size() > 1) {
        printf("Not Unique\n");
    } else {
        printf("(%d, %d): %d\n", res[0].x + 1, res[0].y + 1, res[0].val);
    }
    return 0;
}
