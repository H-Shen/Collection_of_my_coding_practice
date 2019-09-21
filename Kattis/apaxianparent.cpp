// https://open.kattis.com/problems/apaxianparent
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    string Y, P, result;
    cin >> Y >> P;
    if (Y.back() == 'e') {
        result = Y + "x" + P;
    } else if (Y.back() == 'a' || Y.back() == 'o' || Y.back() == 'i' || Y.back() == 'u') {
        Y.pop_back();
        result = Y + "ex" + P;
    } else if (Y.length() >= 2 && Y.at(Y.size() - 2) == 'e' && Y.at(Y.size() - 1) == 'x') {
        result = Y + P;
    } else {
        result = Y + "ex" + P;
    }
    cout << result << endl;

    return 0;
}
