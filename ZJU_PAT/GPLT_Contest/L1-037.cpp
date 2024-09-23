#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << to_string(a) << "/0=Error" << endl;
        return 0;
    }

    if (b < 0) {
        cout << to_string(a) << "/(" << to_string(b) << ")=";
    } else {
        cout << to_string(a) << "/" << to_string(b) << "=";
    }
    printf("%.2f\n", (double) a / (double) b);

    return 0;
}