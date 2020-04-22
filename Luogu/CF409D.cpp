#include <bits/stdc++.h>

using namespace std;

vector<int> A = {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0};

int main() {
    int n;
    cin >> n;
    cout << A.at(n - 1) << '\n';
    return 0;
}