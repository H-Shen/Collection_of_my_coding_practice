#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 26;
vector<char> vec1(MAXN, 0);
vector<char> vec2(MAXN, 0);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string encrypted,original,sEncrypted;
    cin >> encrypted >> original >> sEncrypted;
    int n = (int)encrypted.size();
    bool failed = false;
    for (int i = 0; i < n; ++i) {
        if (vec1[encrypted[i] - 'A'] != 0) {
            if (vec1[encrypted[i] - 'A'] != original[i]) {
                failed = true;
                break;
            }
        }
        else {
            vec1[encrypted[i] - 'A'] = original[i];
        }
    }
    if (failed) {
        cout << "Failed" << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (vec2[original[i] - 'A'] != 0) {
            if (vec2[original[i] - 'A'] != encrypted[i]) {
                failed = true;
                break;
            }
        }
        else {
            vec2[original[i] - 'A'] = encrypted[i];
        }
    }
    if (failed) {
        cout << "Failed" << '\n';
        return 0;
    }
    for (int i = 0; i < MAXN; ++i) {
        if (vec1[i] == 0) {
            failed = true;
            break;
        }
    }
    if (failed) {
        cout << "Failed" << '\n';
        return 0;
    }
    for (auto &i : sEncrypted) {
        i = vec1[i - 'A'];
    }
    cout << sEncrypted << '\n';
    return 0;
}