#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, num;
    cin >> n;
    int even = 0, odd = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num % 2 == 0) {
            ++even;
        } else {
            ++odd;
        }
    }
    cout << odd << ' ' << even << endl;
    return 0;
}