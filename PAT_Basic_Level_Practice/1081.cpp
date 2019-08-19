#include <bits/stdc++.h>


using namespace std;
using ll = long long;

const static string table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";
const int MINLENGTH = 6;

int main() {

    unordered_set<char> tableSet(table.begin(), table.end());

    int n;
    cin >> n;
    getchar();

    string s;
    bool hasNum, hasChar, hasIllegal;

    while (n--) {

        hasNum = false;
        hasChar = false;
        hasIllegal = false;

        getline(cin, s);
        if (s.size() < MINLENGTH) {
            cout << "Your password is tai duan le." << endl;
            continue;
        }

        for (const auto &ch : s) {
            if (tableSet.find(ch) == tableSet.end()) {
                hasIllegal = true;
                break;
            }
            if (isalpha(ch)) {
                hasChar = true;
            }
            if (isdigit(ch)) {
                hasNum = true;
            }
        }

        if (hasIllegal) {
            cout << "Your password is tai luan le." << endl;
        } else if (hasChar && !hasNum) {
            cout << "Your password needs shu zi." << endl;
        } else if (!hasChar && hasNum) {
            cout << "Your password needs zi mu." << endl;
        } else {
            cout << "Your password is wan mei." << endl;
        }
    }
    return 0;
}