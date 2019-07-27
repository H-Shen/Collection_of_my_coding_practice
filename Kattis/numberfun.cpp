// https://open.kattis.com/problems/numberfun
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n;
    bool hasAns = false;
    while (n--) {
        hasAns = false;
        cin >> a >> b >> c;
        vector<int> tmp{a, b, c};
        sort(tmp.begin(), tmp.end());

        do {
            a = tmp[0];
            b = tmp[1];
            c = tmp[2];
            if (a + b == c || a * b == c || a - b == c || (a % b == 0 && a / b == c)) {
                cout << "Possible" << endl;
                hasAns = true;
                break;
            }
        } while (next_permutation(tmp.begin(), tmp.end()));

        if (!hasAns)
            cout << "Impossible" << endl;
    }
    return 0;
}
