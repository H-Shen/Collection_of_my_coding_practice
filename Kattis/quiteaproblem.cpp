// https://open.kattis.com/problems/quiteaproblem
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int WORD_LENGTH = 7;

inline
int check_letter(const char &c, const int &index) {
    switch (index) {
        case 0:
            return c == 'p' || c == 'P';
        case 1:
            return c == 'r' || c == 'R';
        case 2:
            return c == 'o' || c == 'O';
        case 3:
            return c == 'b' || c == 'B';
        case 4:
            return c == 'l' || c == 'L';
        case 5:
            return c == 'e' || c == 'E';
        case 6:
            return c == 'm' || c == 'M';
        default:
            return 0;
    }
}

inline
int read_line() {
    char next;
    int index = 0;
    int found = 0;
    while (true) {
        if (scanf("%c", &next) == EOF) return 0;
        if (next == '\n') {
            printf(found ? "yes\n" : "no\n");
            return 1;
        }
        if (!found) {
            if (check_letter(next, index++)) {
                found = (index == WORD_LENGTH);
            }
            else {
                index = (next == 'p' || next == 'P');
            }
        }
    }
}

int main() {
    while (read_line());
    return 0;
}
