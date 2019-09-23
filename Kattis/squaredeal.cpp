// https://open.kattis.com/problems/squaredeal
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;

    if (h1 * w1 + h2 * w2 + h3 * w3 != h1 * h1) {
        cout << "NO" << endl;
        return 0;
    }

    int counterOfHmax = 1;
    if (h1 == h2) {
        ++counterOfHmax;
    }
    if (h1 == h3) {
        ++counterOfHmax;
    }
    // Parallel place: positive
    if (counterOfHmax == 3 && (w1 + w2 + w3 == h1)) {
        cout << "YES" << endl;
    }
    // Parallel place: negative
    else if (counterOfHmax == 2) {
        cout << "NO" << endl;
    }
    // Rotated place
    else {
        // Case 1:
        if ((h2 + h3 == h1) && (w3 + w1 == h1) && (w2 + w1 == h1)) {
            cout << "YES" << endl;
        }
        // Case 2:
        else if ((h3 + w2 == h1) && (h2 + w1 == h1) && (w3 + w1 == h1)) {
            cout << "YES" << endl;
        }
        // Case 3:
        else if ((h2 + w3 == h1) && (w2 + w1 == h1) && (h3 + w1 == h1)) {
            cout << "YES" << endl;
        }
        // Case 4:
        else if ((w2 + w3 == h1) && (w1 + h2 == h1) && (h3 + w1 == h1)) {
            cout << "YES" << endl;
        }
        // Case 5:
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
