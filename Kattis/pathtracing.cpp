// https://open.kattis.com/problems/pathtracing
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 6;
char op[MAXN];

int main() {

    int i = 0, j = 0;
    int i_min = 0;
    int i_max = 0;
    int j_min = 0;
    int j_max = 0;
    vector<int> steps;  // 1: down 2:up 3:left 4:right
    while (~scanf("%s", op)) {
        if (strcmp(op, "down") == 0) {
            ++i;
            steps.emplace_back(1);
        } else if (strcmp(op, "up") == 0) {
            --i;
            steps.emplace_back(2);
        } else if (strcmp(op, "left") == 0) {
            --j;
            steps.emplace_back(3);
        } else {
            ++j;
            steps.emplace_back(4);
        }
        i_max = max(i_max, i);
        i_min = min(i_min, i);
        j_min = min(j_min, j);
        j_max = max(j_max, j);
    }

    int r = abs(i_max) + abs(i_min) + 1;
    int c = abs(j_max) + abs(j_min) + 1;
    int original_r = abs(i_min);
    int original_c = abs(j_min);

    deque<deque<char> > Maps(r, deque<char>(c, ' '));

    int n = static_cast<int>(steps.size());
    int current_r = original_r;
    int current_c = original_c;
    for (int index = 0; index < n; ++index) {
        Maps.at(current_r).at(current_c) = '*';
        if (steps.at(index) == 1) {
            ++current_r;
        } else if (steps.at(index) == 2) {
            --current_r;
        } else if (steps.at(index) == 3) {
            --current_c;
        } else {
            ++current_c;
        }
    }
    Maps.at(original_r).at(original_c) = 'S';
    Maps.at(current_r).at(current_c) = 'E';

    // add boundaries
    for (auto &item : Maps) {
        item.push_front('#');
        item.push_back('#');
    }
    Maps.push_front(deque<char>(c + 2, '#'));
    Maps.emplace_back(c + 2, '#');

    // output
    for (const auto &index : Maps) {
        for (const auto &ch : index) {
            printf("%c", ch);
        }
        printf("\n");
    }
    return 0;
}
