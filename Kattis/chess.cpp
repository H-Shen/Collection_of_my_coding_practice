// https://open.kattis.com/problems/chess
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int N = 8;
constexpr int MAX_STR_LEN = 3;

char x_1[MAX_STR_LEN];
char x_2[MAX_STR_LEN];
int y_1, y_2, original_i, original_j, dest_i, dest_j;
unordered_set<int> black_pos, white_pos;

pair<int, int> convert(const string &x, const int &y) {
    pair<int, int> result;
    result.first = N - y;
    result.second = x.front() - 'A';
    return result;
}
pair<char, int> convert(const pair<int, int> &pos) {
    pair<char, int> result;
    result.first = pos.second + 'A';
    result.second = N - pos.first;
    return result;
}
int convert(int i, int j) {
    return i * N + j;
}
pair<int, int> convert(int pos) {
    pair<int, int> result;
    result.first = pos / N;
    result.second = pos % N;
    return result;
}
void pre() {
    bool white;
    for (int i = 0; i < N; ++i) {
        white = i % 2 == 0;
        for (int j = 0; j < N; ++j) {
            if (white) {
                white_pos.insert(convert(i, j));
                white = false;
            } else {
                black_pos.insert(convert(i, j));
                white = true;
            }
        }
    }
}
bool has_moves(const string &x1, const int &y1, const string &x2, const int &y2) {
    pair<int, int> temp0 = convert(x1, y1);
    int temp0_ = convert(temp0.first, temp0.second);
    pair<int, int> temp1 = convert(x2, y2);
    int temp1_ = convert(temp1.first, temp1.second);
    if (black_pos.find(temp0_) != black_pos.end() && black_pos.find(temp1_) != black_pos.end()) {
        return true;
    }
    if (white_pos.find(temp0_) != white_pos.end() && white_pos.find(temp1_) != white_pos.end()) {
        return true;
    }
    return false;
}

vector<vector<bool> > vis(N, vector<bool>(N));

unordered_set<int> f(int i, int j) {
    unordered_set<int> result;
    int new_i, new_j;
    bool temp;
    // upper-left
    new_i = i - 1;
    new_j = j - 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            result.insert(convert(new_i, new_j));
            --new_i;
            --new_j;
        }
    } catch (...) {}
    // upper-right
    new_i = i - 1;
    new_j = j + 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            result.insert(convert(new_i, new_j));
            --new_i;
            ++new_j;
        }
    } catch (...) {}
    // lower-left
    new_i = i + 1;
    new_j = j - 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            result.insert(convert(new_i, new_j));
            ++new_i;
            --new_j;
        }
    } catch (...) {}
    // lower-right
    new_i = i + 1;
    new_j = j + 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            result.insert(convert(new_i, new_j));
            ++new_i;
            ++new_j;
        }
    } catch (...) {}
    return result;
}

bool same_diagon() {
    int new_i, new_j;
    bool temp;
    // upper-left
    new_i = original_i - 1;
    new_j = original_j - 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            if (new_i == dest_i && new_j == dest_j) {
                return true;
            }
            --new_i;
            --new_j;
        }
    } catch (...) {}
    // upper-right
    new_i = original_i - 1;
    new_j = original_j + 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            if (new_i == dest_i && new_j == dest_j) {
                return true;
            }
            --new_i;
            ++new_j;
        }
    } catch (...) {}
    // lower-left
    new_i = original_i + 1;
    new_j = original_j - 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            if (new_i == dest_i && new_j == dest_j) {
                return true;
            }
            ++new_i;
            --new_j;
        }
    } catch (...) {}
    // lower-right
    new_i = original_i + 1;
    new_j = original_j + 1;
    try {
        while (true) {
            temp = vis.at(new_i).at(new_j);
            if (new_i == dest_i && new_j == dest_j) {
                return true;
            }
            ++new_i;
            ++new_j;
        }
    } catch (...) {}
    return false;
}

int main() {

    // pre
    pre();

    int t;
    scanf("%d", &t);
    while (t--) {

        scanf("%s %d %s %d", x_1, &y_1, x_2, &y_2);
        auto p = convert(x_1, y_1);
        original_i = p.first;
        original_j = p.second;
        p = convert(x_2, y_2);
        dest_i = p.first;
        dest_j = p.second;

        if (!has_moves(x_1, y_1, x_2, y_2)) {
            printf("Impossible\n");
        } else if (original_i == dest_i && original_j == dest_j) {
            printf("0 %s %d\n", x_1, y_1);
        } else if (same_diagon()) {
            printf("1 %s %d %s %d\n", x_1, y_1, x_2, y_2);
        } else {
            auto path1 = f(original_i, original_j);
            auto path2 = f(dest_i, dest_j);
            for (const auto &i : path1) {
                if (path2.find(i) != path2.end()) {
                    auto pos = convert(convert(i));
                    printf("2 %s %d %c %d %s %d\n", x_1, y_1, pos.first, pos.second, x_2, y_2);
                    break;
                }
            }
        }
    }
    return 0;
}
