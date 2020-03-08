// https://open.kattis.com/problems/turtlemaster
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 8;
vector<vector<char> > A(MAXN, vector<char>(MAXN));

enum class Direction {
    Up, Down, Left, Right
};

int main() {

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            scanf("%c", &A.at(i).at(j));
        }
        getchar();
    }
    string steps;
    char ch;
    while (~scanf("%c", &ch)) {
        if (ch != '\n') {
            steps.push_back(ch);
        }
    }

    int pos_i = MAXN - 1;
    int pos_j = 0;
    Direction dir = Direction::Right;
    int counter = 0;
    for (const char &ch : steps) {
        ++counter;
        if (ch == 'F') {
            if (dir == Direction::Right) {
                ++pos_j;
            } else if (dir == Direction::Left) {
                --pos_j;
            } else if (dir == Direction::Up) {
                --pos_i;
            } else {
                ++pos_i;
            }
            try {
                char temp = A.at(pos_i).at(pos_j);
                if (temp == 'C' || temp == 'I') {
                    printf("Bug!\n");
                    return 0;
                }
                if (temp == 'D' && counter == static_cast<int>(steps.size())) {
                    printf("Diamond!\n");
                    return 0;
                }
            } catch (...) {
                printf("Bug!\n");
                return 0;
            }
        }
        else if (ch == 'R') {
            if (dir == Direction::Right) {
                dir = Direction::Down;
            } else if (dir == Direction::Left) {
                dir = Direction::Up;
            } else if (dir == Direction::Up) {
                dir = Direction::Right;
            } else {
                dir = Direction::Left;
            }
        }
        else if (ch == 'L') {
            if (dir == Direction::Right) {
                dir = Direction::Up;
            } else if (dir == Direction::Left) {
                dir = Direction::Down;
            } else if (dir == Direction::Up) {
                dir = Direction::Left;
            } else {
                dir = Direction::Right;
            }
        }
        else {
            try {
                if (dir == Direction::Right) {
                    if (A.at(pos_i).at(pos_j + 1) == 'I') {
                        A.at(pos_i).at(pos_j + 1) = '.';
                    } else {
                        printf("Bug!\n");
                        return 0;
                    }
                } else if (dir == Direction::Left) {
                    if (A.at(pos_i).at(pos_j - 1) == 'I') {
                        A.at(pos_i).at(pos_j - 1) = '.';
                    } else {
                        printf("Bug!\n");
                        return 0;
                    }
                } else if (dir == Direction::Up) {
                    if (A.at(pos_i - 1).at(pos_j) == 'I') {
                        A.at(pos_i - 1).at(pos_j) = '.';
                    } else {
                        printf("Bug!\n");
                        return 0;
                    }
                } else {
                    if (A.at(pos_i + 1).at(pos_j) == 'I') {
                        A.at(pos_i + 1).at(pos_j) = '.';
                    } else {
                        printf("Bug!\n");
                        return 0;
                    }
                }
            } catch (...) {
                printf("Bug!\n");
                return 0;
            }
        }
    }

    printf("Bug!\n");

    return 0;
}
