// https://open.kattis.com/problems/misa
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int r;
int s;
vector<vector<char> > A;

auto convert = [](int i, int j)->int{
    return i * s + j;
};

struct hash_func_of_pair {
    size_t operator()(const pair<int,int> & v) const {
        return hash<int>()(v.first) ^ hash<int>()(v.second);
    }
};

int solve() {
    pair<int, int> temp_pair;
    unordered_set<pair<int, int>, hash_func_of_pair> temp_unset;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            if (A.at(i).at(j) != '.') {
                // Left
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i).at(j - 1) != '.') {
                        temp_pair.second = convert(i, j - 1);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Right
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i).at(j + 1) != '.') {
                        temp_pair.second = convert(i, j + 1);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Up
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i - 1).at(j) != '.') {
                        temp_pair.second = convert(i - 1, j);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Down
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i + 1).at(j) != '.') {
                        temp_pair.second = convert(i + 1, j);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Upper-Left
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i - 1).at(j - 1) != '.') {
                        temp_pair.second = convert(i - 1, j - 1);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Upper-Right
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i - 1).at(j + 1) != '.') {
                        temp_pair.second = convert(i - 1, j + 1);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Lower-Left
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i + 1).at(j - 1) != '.') {
                        temp_pair.second = convert(i + 1, j - 1);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
                // Lower-Right
                try {
                    temp_pair.first = convert(i, j);
                    if (A.at(i + 1).at(j + 1) != '.') {
                        temp_pair.second = convert(i + 1, j + 1);
                        if (temp_pair.first > temp_pair.second) {
                            swap(temp_pair.first, temp_pair.second);
                        }
                        temp_unset.insert(temp_pair);
                    }
                } catch (...) {}
            }
        }
    }
    return static_cast<int>(temp_unset.size());
}

int update(int i, int j) {
    pair<int, int> temp_pair;
    unordered_set<pair<int, int>, hash_func_of_pair> temp_unset;
    // Left
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i).at(j - 1) != '.') {
            temp_pair.second = convert(i, j - 1);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Right
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i).at(j + 1) != '.') {
            temp_pair.second = convert(i, j + 1);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Up
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i - 1).at(j) != '.') {
            temp_pair.second = convert(i - 1, j);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Down
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i + 1).at(j) != '.') {
            temp_pair.second = convert(i + 1, j);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Upper-Left
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i - 1).at(j - 1) != '.') {
            temp_pair.second = convert(i - 1, j - 1);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Upper-Right
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i - 1).at(j + 1) != '.') {
            temp_pair.second = convert(i - 1, j + 1);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Lower-Left
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i + 1).at(j - 1) != '.') {
            temp_pair.second = convert(i + 1, j - 1);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    // Lower-Right
    try {
        temp_pair.first = convert(i, j);
        if (A.at(i + 1).at(j + 1) != '.') {
            temp_pair.second = convert(i + 1, j + 1);
            if (temp_pair.first > temp_pair.second) {
                swap(temp_pair.first, temp_pair.second);
            }
            temp_unset.insert(temp_pair);
        }
    } catch (...) {}
    return static_cast<int>(temp_unset.size());
}

int main() {

    scanf("%d %d", &r, &s);
    A.resize(r);
    for (auto &i : A) {
        i.resize(s);
    }

    vector<pair<int, int> > empty_positions;
    getchar();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            scanf("%c", &A.at(i).at(j));
            if (A.at(i).at(j) == '.') {
                empty_positions.emplace_back(make_pair(i, j));
            }
        }
        getchar();
    }

    int max_val = -1;
    if (empty_positions.empty()) {
        max_val = solve();
    } else {
        int original = solve();
        int counter;
        for (const auto &[pos_i, pos_j] : empty_positions) {
            A.at(pos_i).at(pos_j) = 'o';
            counter = original + update(pos_i, pos_j);
            max_val = max(counter, max_val);
            A.at(pos_i).at(pos_j) = '.';
        }
    }
    printf("%d\n", max_val);


    return 0;
}
