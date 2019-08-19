#include <bits/stdc++.h>

using namespace std;
const int maxn = 169;

int main() {

    vector<string> a = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
                        "aug", "sep", "oct", "nov", "dec"};
    vector<string> b = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer",
                        "jou"};

    unordered_map<string, int> A;
    unordered_map<int, string> A_rev;

    int i;
    int pos1 = 0;
    int pos0 = 0;
    string tmpStr;

    for (i = 0; i < maxn; ++i) {
        if (i >= 0 && i <= 12) {
            A_rev[i] = a.at(static_cast<size_t>(i));
            A[a.at(static_cast<size_t>(i))] = i;
        } else {
            if (pos0 == 0) {
                tmpStr = b.at(static_cast<size_t>(pos1));
            } else {
                tmpStr = b.at(static_cast<size_t>(pos1)) + ' ' + a.at(static_cast<size_t>(pos0));
            }
            A_rev[i] = tmpStr;
            A[tmpStr] = i;
            if (pos0 == 12) {
                pos0 = 0;
                ++pos1;
                continue;
            }
            ++pos0;
        }
    }

    int n, tmp;
    string input;
    cin >> n;
    getchar();

    while (n--) {
        getline(cin, input);
        try {
            tmp = stoi(input);
        } catch (...) {
            cout << A[input] << endl;
            continue;
        }
        cout << A_rev[tmp] << endl;
    }

    return 0;
}