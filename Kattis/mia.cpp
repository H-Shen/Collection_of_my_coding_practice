// https://open.kattis.com/problems/mia
//
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> A;

inline static
int getMax(int a, int b) {
    return max(10*a + b, 10*b + a);
}

int main() {

    // pre
    int maxVal = -1;
    for (int i = 1; i <= 66; ++i) {
        if (i == 12 || i == 21) {
            continue;
        }
        if (i % 10 == i / 10) {
            continue;
        }
        A[i] = i;
        maxVal = max(maxVal, i);
    }

    for (int i = 11; i <= 66; i += 11) {
        ++maxVal;
        A[i] = maxVal;
    }

    ++maxVal;
    A[12] = maxVal;
    A[21] = maxVal;

    int s0, s1, r0, r1, player1, player2;
    while (true) {
        cin >> s0 >> s1 >> r0 >> r1;
        if (s0 == s1 && s1 == r0 && r0 == r1 && r1 == 0) {
            break;
        }
        player1 = A[getMax(s0, s1)];
        player2 = A[getMax(r0, r1)];
        if (player1 > player2) {
            cout << "Player 1 wins." << endl;
        } else if (player1 < player2) {
            cout << "Player 2 wins." << endl;
        } else {
            cout << "Tie." << endl;
        }
    }

    return 0;
}
