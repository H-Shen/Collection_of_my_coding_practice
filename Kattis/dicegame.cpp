// https://open.kattis.com/problems/dicegame
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int a1, b1, a2, b2;
    int A1, B1, A2, B2;
    int temp0, temp1;
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> A1 >> B1 >> A2 >> B2;
    int gunnarWin = 0;
    int emmaWin =  0;
    for (int i = a1; i <= b1; ++i) {
        for (int j = a2; j <= b2; ++j) {
            for (int k = A1; k <= B1; ++k) {
                for (int n = A2; n <= B2; ++n) {
                    temp0 = i + j;
                    temp1 = k + n;
                    if (temp0 > temp1)  {
                        ++gunnarWin;
                    } else if (temp0 < temp1) {
                        ++emmaWin;
                    }
                }
            }
        }
    }
    if (gunnarWin > emmaWin) {
        cout << "Gunnar" << endl;
    } else if (gunnarWin < emmaWin) {
        cout << "Emma" << endl;
    } else {
        cout << "Tie" << endl;
    }

    return 0;
}
