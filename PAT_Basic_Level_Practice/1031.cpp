#include <bits/stdc++.h>

using namespace std;

vector<int> A = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
unordered_map<int, char> B = {{0,  '1'},
                              {1,  '0'},
                              {2,  'X'},
                              {3,  '9'},
                              {4,  '8'},
                              {5,  '7'},
                              {6,  '6'},
                              {7,  '5'},
                              {8,  '4'},
                              {9,  '3'},
                              {10, '2'}};

int main() {
    int n, i;
    cin >> n;
    getchar();
    string s;
    vector<string> res;
    bool hasDigit;
    int sum = 0;

    while (n--) {

        getline(cin, s);
        hasDigit = false;
        sum = 0;

        if (s.size() != 18) {
            res.push_back(s);
            continue;
        }
        for (i = 0; i < 17; ++i) {
            if (!isdigit(s[i])) {
                hasDigit = true;
                break;
            }
        }
        if (hasDigit) {
            res.push_back(s);
            continue;
        }

        for (i = 0; i < 17; ++i) {
            sum = sum + (s[i] - '0') * A[i];
        }
        sum %= 11;
        if (s[17] != B[sum]) {
            res.push_back(s);
        }

    }

    if (res.empty()) {
        cout << "All passed" << endl;
    } else {
        for (const auto &i : res) {
            cout << i << endl;
        }
    }

    return 0;
}