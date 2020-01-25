// https://open.kattis.com/problems/countingstars
//
#include <bits/extc++.h>

using namespace std;

constexpr int maxn = 10050;
vector<int> father(maxn); // Father nodes
vector<int> Rank(maxn); // Rank

int find(int x) {
    if (x != father.at(x))
        father.at(x) = find(father.at(x));
    return father.at(x);
}

void merge(int x, int y) {

    x = find(x);
    y = find(y);

    if (Rank.at(x) > Rank.at(y)) {
        father.at(y) = x;
    } else {
        father.at(x) = y;
        if (Rank.at(x) == Rank.at(y))
            ++Rank.at(y);
    }
}

void reset() {
    for (int i = 0; i < maxn; i++) {
        father.at(i) = i;
        Rank.at(i) = 0;
    }
}

int main() {

    int col, row, down, right, counter;
    int kase = 1;

    while (~scanf("%d %d", &row, &col)) {

        reset();
        getchar();
        counter = 0;
        vector<vector<char> > A(row, vector<char>(col));
        for (auto &i : A) {
            for (auto &j : i) {
                scanf("%c", &j);
            }
            getchar();
        }

        // first pass
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (A.at(i).at(j) == '-') {
                    down = i + 1;
                    right = j + 1;
                    // merge the current pos and the south pos
                    if (down < row && A.at(down).at(j) == '-') {
                        merge(col * i + j, col * down + j);
                    }
                    // merge the current pos and the east pos
                    if (right < col && A.at(i).at(right) == '-') {
                        merge(col * i + j, col * i + right);
                    }
                }
            }
        }

        // second pass, we calculate the number of disjoint sets by counting
        // the number of roots in each disjoint set
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int currentPosition = col * i + j;
                if (A.at(i).at(j) == '-' && father.at(currentPosition) == currentPosition) {
                    ++counter;
                }
            }
        }

        // output
        printf("Case %d: %d\n", kase, counter);
        ++kase;
    }

    return 0;
}
