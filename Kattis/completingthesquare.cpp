// https://open.kattis.com/problems/completingthesquare
//
#include <bits/stdc++.h>

using namespace std;

// This algorithm obtains the coordinates of the 4th point of a rectangle if coordinates of the other 3 points are
// given.

inline static
pair<int, int> getFourthCoord(int x1, int y1, int x2, int y2, int x3, int y3) {

    // Let (x1, y1) be A, (x2, y2) be B, (x3, y3) be C, then if angle BAC is a right angle, then the fourth point is
    // (x2 + x3 - x1, y2 + y3 - y1), so we adjust (x1, y1) to make sure such BAC exists.

    // Case 1: Adjust if vector BA(x2 - x1, y2 - y1) cross-dot BC(x3 - x2, y3 - y2) == 0.
    if ((x2 - x1) * (x3 - x2) + (y2 - y1) * (y3 - y2) == 0) {
        swap(x1, x2);
        swap(y1, y2);
    }
        // Case 1: Adjust if vector CA(x1 - x3, y1 - y3) cross-dot CB(x2 - x3, y2 - y3) == 0.
    else if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) == 0) {
        swap(x1, x3);
        swap(y1, y3);
    }
    return {x2 + x3 - x1, y2 + y3 - y1};
}

int main() {

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    auto result = getFourthCoord(x1, y1, x2, y2, x3, y3);
    cout << result.first << ' ' << result.second << endl;

    return 0;
}
