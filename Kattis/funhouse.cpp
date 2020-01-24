// https://open.kattis.com/problems/funhouse
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int row, col;
    int kase = 1;
    while (true) {
        scanf("%d %d", &col, &row);
        if (col == 0 && row == 0) {
            break;
        }
        vector<vector<char> > A(row, vector<char>(col));
        getchar();
        int entrance_i{};
        int entrance_j{};
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                scanf("%c", &A.at(i).at(j));
                if (A.at(i).at(j) == '*') {
                    entrance_i = i;
                    entrance_j = j;
                }
            }
            getchar();
        }

        int current_direction = 0;
        // 0: down
        // 1: up
        // 2: right
        // 3: left
        if (entrance_i == 0) {
            current_direction = 0;
        }
        else if (entrance_i == row - 1) {
            current_direction = 1;
        }
        else if (entrance_j == 0) {
            current_direction = 2;
        }
        else {
            current_direction = 3;
        }

        int trace_i = entrance_i;
        int trace_j = entrance_j;
        int exit_i{};
        int exit_j{};

        auto change_direction = [&](){
            if (A.at(trace_i).at(trace_j) == '/') {
                switch (current_direction) {
                    case 0:
                        current_direction = 3;
                        break;
                    case 1:
                        current_direction = 2;
                        break;
                    case 2:
                        current_direction = 1;
                        break;
                    default:
                        current_direction = 0;
                        break;
                }
            } else if (A.at(trace_i).at(trace_j) == '\\') {
                switch (current_direction) {
                    case 0:
                        current_direction = 2;
                        break;
                    case 1:
                        current_direction = 3;
                        break;
                    case 2:
                        current_direction = 0;
                        break;
                    default:
                        current_direction = 1;
                        break;
                }
            }
        };

        while (true) {
            switch (current_direction) {
                case 0:
                    ++trace_i;
                    change_direction();
                    break;
                case 1:
                    --trace_i;
                    change_direction();
                    break;
                case 2:
                    ++trace_j;
                    change_direction();
                    break;
                default:
                    --trace_j;
                    change_direction();
                    break;
            }
            exit_i = trace_i;
            exit_j = trace_j;
            if (A.at(exit_i).at(exit_j) == 'x') {
                break;
            }
        }
        A.at(exit_i).at(exit_j) = '&';

        // output
        printf("HOUSE %d\n", kase);
        ++kase;
        for (auto &i : A) {
            for (auto &j : i) {
                printf("%c", j);
            }
            printf("\n");
        }
    }

    return 0;
}
