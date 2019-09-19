// https://open.kattis.com/problems/bossbattle
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    // 3 exceptions
    if (n <= 3) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> A(n, 0);
    int idxOfBomb = 2;
    int idxOfBoss = 0;
    int counter = 1;

    while (true) {

        ++counter;

        ++idxOfBoss;
        if (idxOfBoss == n) {
            idxOfBoss = 0;
        }
        idxOfBomb += 2;
        if (idxOfBomb == n) {
            idxOfBomb = 0;
        }
        if (idxOfBomb == n + 1) {
            idxOfBomb = 1;
        }

        //condition to exit
        if (idxOfBomb == n - 1) {
            if (idxOfBoss == 0 || idxOfBoss == n - 1 || idxOfBoss == n - 2) {
                break;
            }
        }
        else if (idxOfBomb == 0) {
            if (idxOfBoss == n - 1 || idxOfBoss == 0 || idxOfBoss == 1) {
                break;
            }
        }
        else {
            if (idxOfBoss == idxOfBomb || idxOfBoss == idxOfBomb - 1 || idxOfBoss == idxOfBomb + 1) {
                break;
            }
        }
    }
    cout << counter << endl;


    return 0;
}
