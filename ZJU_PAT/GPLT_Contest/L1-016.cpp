#include <bits/stdc++.h>

using namespace std;

const int GAP = 48, MAXN = 18, MOD = 11;

vector<int> W = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
unordered_map<string, char> A = {{"0",  '1'},
                                 {"1",  '0'},
                                 {"2",  'X'},
                                 {"3",  '9'},
                                 {"4",  '8'},
                                 {"5",  '7'},
                                 {"6",  '6'},
                                 {"7",  '5'},
                                 {"8",  '4'},
                                 {"9",  '3'},
                                 {"10", '2'}};

int main() {

    int n, i, sum;
    string s;
    cin >> n;
    int k = 0;
    vector<string> res;

    while (n--) {
        cin >> s;
        sum = 0;
        for (i = 0; i < MAXN; ++i) {
            if (i < MAXN - 1) {
                if (s[i] < '0' || s[i] > '9') {
                    ++k;
                    res.push_back(s);
                    break;
                } else {
                    sum += (s[i] - GAP) * W[i];
                }
            } else if (i == MAXN - 1) {
                string val = to_string(sum % MOD);
                if (A.find(val) == A.end() || A[val] != s[i]) {
                    ++k;
                    res.push_back(s);
                }
            }
        }
    }

    if (k == 0) {
        cout << "All passed" << endl;
    } else {
        for (i = 0; i < k; ++i) {
            cout << res[i] << endl;
        }
    }
    return 0;
}