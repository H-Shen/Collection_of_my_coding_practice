// https://open.kattis.com/problems/peg
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    vector<vector<char> > A;
    char ch;
    vector<char> temp_vec;
    while (~scanf("%c", &ch)) {
        if (ch == '\n') {
            A.emplace_back(temp_vec);
            vector<char>().swap(temp_vec);
        } else {
            temp_vec.push_back(ch);
        }
    }
    int r = static_cast<int>(A.size());
    int c = static_cast<int>(A.front().size());
    vector<pair<int, int> > position_of_empty_slots;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (A.at(i).at(j) == '.') {
                position_of_empty_slots.emplace_back(make_pair(i, j));
            } else if (A.at(i).at(j) != 'o') {
                A.at(i).at(j) = '#';
            }
        }
    }

    int counter = 0;
    for (const auto &[i, j] : position_of_empty_slots) {
        // left
        try {
            if (A.at(i).at(j - 1) == 'o' && A.at(i).at(j - 2) == 'o') {
                ++counter;
            }
        } catch (...) {}
        // right
        try {
            if (A.at(i).at(j + 1) == 'o' && A.at(i).at(j + 2) == 'o') {
                ++counter;
            }
        } catch (...) {}
        // up
        try {
            if (A.at(i - 1).at(j) == 'o' && A.at(i - 2).at(j) == 'o') {
                ++counter;
            }
        } catch (...) {}
        // down
        try {
            if (A.at(i + 1).at(j) == 'o' && A.at(i + 2).at(j) == 'o') {
                ++counter;
            }
        } catch (...) {}
    }
    printf("%d\n", counter);

    return 0;
}
