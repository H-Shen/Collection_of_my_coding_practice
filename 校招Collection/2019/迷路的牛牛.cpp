// https://www.nowcoder.com/practice/fc72d3493d7e4be883e931d507352a4a

#include <bits/stdc++.h>

using namespace std;

const vector<char> Direction {'N', 'E', 'S', 'W'};
int currentDirection = 0;

inline static
void turn(bool isLeft) {
    if (isLeft) {
        if (currentDirection == 0) {
            currentDirection = 3;
        } else {
            --currentDirection;
        }
    } else {
        if (currentDirection == 3) {
            currentDirection = 0;
        } else {
            ++currentDirection;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    int N;
    string s;
    cin >> N >> s;
    for (const char &ch : s) {
        if (ch == 'L') {
            turn(true);
        } else {
            turn(false);
        }
    }
    cout << Direction.at(currentDirection) << endl;

    return 0;
}