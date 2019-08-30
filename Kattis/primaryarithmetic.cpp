// https://open.kattis.com/problems/primaryarithmetic
//
#include <bits/stdc++.h>

using namespace std;

const int MAXN_ADD = 30;
int numx[MAXN_ADD], numy[MAXN_ADD];

int Add(string &x, string &y) {

    int carryCounter = 0;
    string res;
    memset(numx, 0, sizeof(numx));
    memset(numy, 0, sizeof(numy));
    int lenx = x.size(), leny = y.size();
    int maxlen = lenx > leny ? lenx : leny;


    for (int i = 0; i < lenx; i++)numx[lenx - i - 1] = x[i] - '0';
    for (int i = 0; i < leny; i++)numy[leny - i - 1] = y[i] - '0';

    for (int i = 0; i <= maxlen; i++) {
        numx[i] += numy[i];
        if (numx[i] > 9) {
            ++carryCounter;
            numx[i + 1] += numx[i] / 10;
            numx[i] %= 10;
        }
    }

    int i = maxlen + 2;
    for (; i > 0 && !numx[i];)
        i--;
    for (; i >= 0; i--)
        res += numx[i] + '0';
    return carryCounter;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    while (true) {
        cin >> a >> b;
        if (a == "0" && b == "0") {
            break;
        }
        int carryCounter = Add(a, b);
        if (carryCounter == 0) {
            cout << "No carry operation." << endl;
        } else if (carryCounter == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << carryCounter << " carry operations." << endl;
        }
    }

    return 0;
}
