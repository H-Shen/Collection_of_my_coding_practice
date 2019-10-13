// https://open.kattis.com/problems/prozor
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int r, s, k;
    scanf("%d %d %d", &r, &s, &k);
    getchar();

    vector<vector<char> > A(r, vector<char>(s));
    for (auto &i : A) {
        for (auto &j : i) {
            scanf("%c", &j);
        }
        getchar();
    }

    vector<vector<char> > A_inner(r - 2, vector<char>(s - 2));
    for (int i = 0; i < r - 2; ++i) {
        for (int j = 0; j < s - 2; ++j) {
            A_inner.at(i).at(j) = A.at(i + 1).at(j + 1);
        }
    }

    int length = k - 2;
    int max_killed = -1;
    int i_max_killed = 0;
    int j_max_killed = 0;
    for (int i = 0; i < r - 2; ++i) {
        for (int j = 0; j < s - 2; ++j) {
            //
            int counter = 0;
            try {
                for (int i_ = i; i_ < i + length; i_++) {
                    for (int j_ = j; j_ < j + length; j_++) {
                        if (A_inner.at(i_).at(j_) == '*') {
                            ++counter;
                        }
                    }
                }
            } catch (...) {
                continue;
            }
            if (counter > max_killed) {
                max_killed = counter;
                i_max_killed = i;
                j_max_killed = j;
            }
        }
    }

    // output
    printf("%d\n", max_killed);
    for (int j = j_max_killed; j < j_max_killed + k; ++j) {
        A.at(i_max_killed).at(j) = '-';
    }
    for (int j = j_max_killed; j < j_max_killed + k; ++j) {
        A.at(i_max_killed + k - 1).at(j) = '-';
    }
    for (int i = i_max_killed; i < i_max_killed + k; ++i) {
        A.at(i).at(j_max_killed) = '|';
    }
    for (int i = i_max_killed; i < i_max_killed + k; ++i) {
        A.at(i).at(j_max_killed + k - 1) = '|';
    }
    // Four corners
    A.at(i_max_killed).at(j_max_killed) = '+';
    A.at(i_max_killed + k - 1).at(j_max_killed) = '+';
    A.at(i_max_killed).at(j_max_killed + k - 1) = '+';
    A.at(i_max_killed + k - 1).at(j_max_killed + k - 1) = '+';

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            printf("%c", A.at(i).at(j));
        }
        printf("\n");
    }

    return 0;
}
