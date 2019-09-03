// https://open.kattis.com/problems/hangingout
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int L, x, val;
    string s;
    int counter = 0;
    int currentPeople = 0;
    cin >> L >> x;
    while (x--) {
        cin >> s >> val;
        if (s == "enter") {
            if (currentPeople + val > L) {
                ++counter;
            } else {
                currentPeople += val;
            }
        } else {
            currentPeople -= val;
        }
    }
    cout << counter << endl;


    return 0;
}
