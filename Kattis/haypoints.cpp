// https://open.kattis.com/problems/haypoints
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int m;
    int n;
    cin >> m >> n;
    string job;
    int salary;
    unordered_map<string, int> A;
    while (m--) {
        cin >> job >> salary;
        A[job] = salary;
    }
    string description;
    string tempStr;
    while (n--) {
        int sum = 0;
        while (true) {
            cin >> tempStr;
            if (tempStr == ".") {
                break;
            }
            if (A.find(tempStr) != A.end()) {
                sum += A[tempStr];
            }
        }
        cout << sum << endl;
    }


    return 0;
}
