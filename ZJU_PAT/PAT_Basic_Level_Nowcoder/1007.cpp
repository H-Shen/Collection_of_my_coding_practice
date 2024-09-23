#include <bits/stdc++.h>

using namespace std;

long long int a[60];

void cow(long long int N) {
    long long int i, j;
    if (N <= 5) {
        for (i = 0; i < N; i++)
            a[i] = i;
    } else {
        for (j = 5; j <= N; j++)
            a[j] = a[j - 1] + a[j - 3];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cow(5);
    cow(56);
    int n;
    while (cin >> n) {
        cout << a[n] << endl;
    }
    return 0;
}