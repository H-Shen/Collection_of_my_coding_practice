#include <bits/stdc++.h>

using namespace std;

void zfill(string &a) {
    string zfillSeg(4 - a.size(), '0');
    a = zfillSeg + a;
}

int noDuplicateNum(const int &a) {
    string k = to_string(a);
    zfill(k);
    unordered_set<char> tmp(k.begin(), k.end());
    return tmp.size();
}

int main() {

    int y, y0, obj;
    cin >> y >> obj;
    y0 = y;

    while (noDuplicateNum(y) != obj) {
        ++y;
    }
    string yStr = to_string(y);
    zfill(yStr);
    cout << y - y0 << ' ' << yStr << endl;

    return 0;
}