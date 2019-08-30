// https://ac.nowcoder.com/acm/contest/395/A

#include <bits/stdc++.h>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;
    long long a_num = 1;
    for (const char &ch : a) {
        a_num *= static_cast<long long>(ch - 'A' + 1);
    }
    long long b_num = 1;
    for (const char &ch : b) {
        b_num *= static_cast<long long>(ch - 'A' + 1);
    }
    if (a_num % 47 == b_num % 47) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }

    return 0;
}
