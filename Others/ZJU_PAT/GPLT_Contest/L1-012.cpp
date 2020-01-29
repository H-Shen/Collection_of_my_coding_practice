#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> A = {1};
    int len = A.size();
    int val = 1;
    while (len != 12) {
        val *= 2;
        A.push_back(val);
        ++len;
    }
    int n;
    cin >> n;
    cout << "2^" << n << " = " << A[n] << endl;
    return 0;
}