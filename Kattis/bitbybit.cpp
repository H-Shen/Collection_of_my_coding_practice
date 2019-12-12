// https://open.kattis.com/problems/bitbybit
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string instruction;
    int i;
    int j;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> A(32, -1);
        while (n--) {
            cin >> instruction;
            if (instruction == "SET") {
                cin >> i;
                A.at(31 - i) = 1;
            }
            else if (instruction == "CLEAR") {
                cin >> i;
                A.at(31 - i) = 0;
            }
            else if (instruction == "OR") {
                cin >> i >> j;
                if (A.at(31 - i) == -1 && A.at(31 - j) == -1) {
                    // do nothing
                }
                else if (A.at(31 - i) != -1 && A.at(31 - j) == -1) {
                    if (A.at(31 - i) == 1) {
                        A.at(31 - i) = 1;
                    } else {
                        A.at(31 - i) = -1;
                    }
                }
                else if (A.at(31 - i) == -1 && A.at(31 - j) != -1) {
                    if (A.at(31 - j) == 1) {
                        A.at(31 - i) = 1;
                    } else {
                        A.at(31 - i) = -1;
                    }
                }
                else {
                    A.at(31 - i) = A.at(31 - i) | A.at(31 - j);
                }
            }
            else {
                cin >> i >> j;
                if (A.at(31 - i) == -1 && A.at(31 - j) == -1) {
                    // do nothing
                }
                else if (A.at(31 - i) != -1 && A.at(31 - j) == -1) {
                    if (A.at(31 - i) == 1){
                        A.at(31 - i) = -1;
                    } else {
                        A.at(31 - i) = 0;
                    }
                }
                else if (A.at(31 - i) == -1 && A.at(31 - j) != -1) {
                    if (A.at(31 - j) == 1) {
                        A.at(31 - i) = -1;
                    } else {
                        A.at(31 - i) = 0;
                    }
                }
                else {
                    A.at(31 - i) = A.at(31 - i) & A.at(31 - j);
                }
            }
        }
        for (const auto &i : A) {
            if (i == -1) {
                cout << '?';
            } else {
                cout << i;
            }
        }
        cout << endl;
    }


    return 0;
}
