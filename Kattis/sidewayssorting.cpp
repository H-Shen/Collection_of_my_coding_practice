// https://open.kattis.com/problems/sidewayssorting
//
#include <bits/stdc++.h>

using namespace std;

inline static
bool myComp(const char &lhs, const char &rhs) {
    return tolower(lhs) < tolower(rhs);
}

int main() {

    int r, c;
    bool firstCase = true;

    while (true) {

        scanf("%d %d", &r, &c);
        if (r == 0 && c == 0) {
            break;
        }
        getchar();

        if (firstCase) {
            firstCase = false;
        } else {
            putchar('\n');
        }

        vector<vector<char> > A(r, vector<char>(c));
        for (auto &i : A) {
            for (auto &j : i) {
                scanf("%c", &j);
            }
            getchar();
        }
        vector<string> B(c);
        auto it = B.begin();
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                it->push_back(A.at(j).at(i));
            }
            ++it;
        }

        sort(begin(B), end(B), [](const string &lhs, const string &rhs) {
            return lexicographical_compare(begin(lhs), end(lhs), begin(rhs), end(rhs), myComp);
        });

        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                A.at(j).at(i) = B.at(i).at(j);
            }
        }
        // output
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                printf("%c", A.at(i).at(j));
            }
            putchar('\n');
        }
    }

    return 0;
}
