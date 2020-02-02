// https://open.kattis.com/problems/gamerank
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAX_LENGTH = 10005;
char s[MAX_LENGTH];
unordered_map<int, int> rank2stars;

int main() {

    // pre
    for (int i = 1; i <= 10; ++i) {
        rank2stars[i] = 5;
    }
    for (int i = 11; i <= 15; ++i) {
        rank2stars[i] = 4;
    }
    for (int i = 16; i <= 20; ++i) {
        rank2stars[i] = 3;
    }
    for (int i = 21; i <= 25; ++i) {
        rank2stars[i] = 2;
    }

    scanf("%s", s);
    int current_rank = 25;
    int current_star = 0;
    int consecutive_win = 0;
    bool has_bonus_star;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == 'L') {
            if (current_rank == 20) {
                if (current_star > 0) {
                    --current_star;
                }
            }
            else if (current_rank < 20 && current_rank >= 1) {
                if (current_star > 0) {
                    --current_star;
                } else {
                    ++current_rank;
                    current_star = rank2stars[current_rank] - 1;
                }
            }
            consecutive_win = 0;
        } else {
            if (current_rank >= 1) {
                has_bonus_star = current_rank >= 6 && current_rank <= 25 &&
                                 consecutive_win >= 2;
                if (current_star < rank2stars[current_rank]) {
                    ++current_star;
                } else {
                    --current_rank;
                    if (current_rank < 0) {
                        current_star = -1;
                    } else {
                        current_star = 1;
                    }
                }
                if (has_bonus_star && current_rank >= 1) {
                    if (current_star < rank2stars[current_rank]) {
                        ++current_star;
                    } else {
                        --current_rank;
                        current_star = 1;
                    }
                }
                ++consecutive_win;
            }
        }
    }

    if (current_rank <= 25 && current_rank >= 1) {
        printf("%d\n", current_rank);
    } else {
        printf("Legend\n");
    }

    return 0;
}
