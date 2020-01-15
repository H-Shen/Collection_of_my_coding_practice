// https://open.kattis.com/problems/glitchbot
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 10;
char cstr[MAXN];

enum class DIRECTION {
    SOUTH, NORTH, WEST, EAST
};

inline static
bool check(const vector<string> &instructions, int dest_x, int dest_y) {
    int x = 0;
    int y = 0;
    DIRECTION direction = DIRECTION::NORTH;
    for (const auto &i : instructions) {
        if (i == "Forward") {
            switch (direction) {
                case DIRECTION::NORTH:
                    ++y;
                    break;
                case DIRECTION::SOUTH:
                    --y;
                    break;
                case DIRECTION::EAST:
                    ++x;
                    break;
                default:
                    --x;
                    break;
            }
        } else if (i == "Right") {
            switch (direction) {
                case DIRECTION::NORTH:
                    direction = DIRECTION::EAST;
                    break;
                case DIRECTION::SOUTH:
                    direction = DIRECTION::WEST;
                    break;
                case DIRECTION::EAST:
                    direction = DIRECTION::SOUTH;
                    break;
                default:
                    direction = DIRECTION::NORTH;
                    break;
            }
        } else {
            switch (direction) {
                case DIRECTION::NORTH:
                    direction = DIRECTION::WEST;
                    break;
                case DIRECTION::SOUTH:
                    direction = DIRECTION::EAST;
                    break;
                case DIRECTION::EAST:
                    direction = DIRECTION::NORTH;
                    break;
                default:
                    direction = DIRECTION::SOUTH;
                    break;
            }
        }
    }
    return (x == dest_x && y == dest_y);
}

int main() {

    int x, y;
    int n;
    string s;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    vector<string> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        A.at(i) = cstr;
    }
    for (int i = 0; i < n; ++i) {
        if (A.at(i) == "Forward") {
            A.at(i) = "Left";
            if (check(A, x, y)) {
                printf("%d Left\n", i + 1);
                return 0;
            }
            A.at(i) = "Right";
            if (check(A, x, y)) {
                printf("%d Right\n", i + 1);
                return 0;
            }
            // restore the status
            A.at(i) = "Forward";
        } else if (A.at(i) == "Left") {
            A.at(i) = "Forward";
            if (check(A, x, y)) {
                printf("%d Forward\n", i + 1);
                return 0;
            }
            A.at(i) = "Right";
            if (check(A, x, y)) {
                printf("%d Right\n", i + 1);
                return 0;
            }
            // restore the status
            A.at(i) = "Left";
        } else {
            A.at(i) = "Forward";
            if (check(A, x, y)) {
                printf("%d Forward\n", i + 1);
                return 0;
            }
            A.at(i) = "Left";
            if (check(A, x, y)) {
                printf("%d Left\n", i + 1);
                return 0;
            }
            // restore the status
            A.at(i) = "Right";
        }
    }

    return 0;
}
