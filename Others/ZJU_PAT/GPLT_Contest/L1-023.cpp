#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> A = {{'G', 0},
                              {'P', 0},
                              {'L', 0},
                              {'T', 0}};
vector<char> order = {'G', 'P', 'L', 'T'};

int main() {

    string s;
    cin >> s;
    int i;
    int len = s.size();
    for (i = 0; i < len; ++i) {
        if (A.find(toupper(s[i])) != A.end()) {
            A[toupper(s[i])]++;
        }
    }
    int pos = 0;
    while (!(A['G'] == 0 && A['P'] == 0 && A['L'] == 0 && A['T'] == 0)) {
        if (pos == 5) {
            pos = 0;
        }
        if (A[order[pos]] == 0) {
            pos++;
            continue;
        } else {
            cout << order[pos];
            A[order[pos]]--;
            pos++;
        }
    }
    cout << endl;
    return 0;
}