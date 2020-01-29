#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> A = {{"ChuiZi",  "Bu"},
                                   {"Bu",      "JianDao"},
                                   {"JianDao", "ChuiZi"}};

int main() {

    int k;
    cin >> k;
    string input;
    int cnt = 0;

    while (cin >> input) {
        if (input == "End") {
            break;
        }
        if (cnt == k) {
            cout << input << endl;
            cnt = 0;
        } else {
            cout << A[input] << endl;
            ++cnt;
        }
    }
    return 0;
}