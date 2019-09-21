// https://open.kattis.com/problems/zanzibar
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n, currentTurtle, nonLocalBornTurtle, turtleCount;
    cin >> n;
    while (n--) {
        currentTurtle = 0;
        nonLocalBornTurtle = 0;
        while (true) {
            cin >> turtleCount;
            if (turtleCount == 0) {
                break;
            }
            if (currentTurtle == 0) {
                currentTurtle = turtleCount;
            } else if (turtleCount > 2 * currentTurtle) {
                nonLocalBornTurtle += turtleCount - 2 * currentTurtle;
                currentTurtle = turtleCount;
            } else {
                currentTurtle = turtleCount;
            }
        }
        cout << nonLocalBornTurtle << endl;
    }


    return 0;
}
