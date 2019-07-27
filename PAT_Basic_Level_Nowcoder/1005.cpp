#include <bits/stdc++.h>

const int MOD = 1000000;

using namespace std;

unordered_map<int, int> table;

void fib(int n) {
    table[0] = 1;
    table[1] = 1;
    int i = 2, a = 1, b = 1;
    while (i <= n) {
        int temp = b % MOD;
        b = (a % MOD + b % MOD) % MOD;
        a = temp;
        table[i++] = b;
    }
}

int main() {
    fib(100000);
    int item;
    while (scanf("%d", &item) != EOF) {

        int result = table[item];

        if (item >= 29) {
            stringstream ss;
            string s;
            ss << table[item];
            ss >> s;
            string zfill(6 - s.length(), '0');
            s = zfill + s;
            cout << s << endl;
        } else
            printf("%d\n", result);

    }
    return 0;
}