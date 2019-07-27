// https://open.kattis.com/problems/filip
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string stra, strb;
    cin >> stra >> strb;
    reverse(stra.begin(), stra.end());
    reverse(strb.begin(), strb.end());

    int a = stoi(stra);
    int b = stoi(strb);
    if (a > b) {
        cout << a;
    } else {
        cout << b;
    }
    cout << endl;

    return 0;
}
