// https://open.kattis.com/problems/marko
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1005;
char cstr[MAXN];

int main() {

    unordered_map<int, unordered_set<char> > A;
    string s;
    unordered_map<char, char> B;

    s = "abc";
    for (auto i : s) {
        A[2].insert(i);
        B[i] = '2';
    }
    s = "def";
    for (auto i : s) {
        A[3].insert(i);
        B[i] = '3';
    }
    s = "ghi";
    for (auto i : s) {
        A[4].insert(i);
        B[i] = '4';
    }
    s = "jkl";
    for (auto i : s) {
        A[5].insert(i);
        B[i] = '5';
    }
    s = "mno";
    for (auto i : s) {
        A[6].insert(i);
        B[i] = '6';
    }
    s = "pqrs";
    for (auto i : s) {
        A[7].insert(i);
        B[i] = '7';
    }
    s = "tuv";
    for (auto i : s) {
        A[8].insert(i);
        B[i] = '8';
    }
    s = "wxyz";
    for (auto i : s) {
        A[9].insert(i);
        B[i] = '9';
    }

    int n;
    scanf("%d", &n);
    vector<string> L(n);
    vector<string> L_convert(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        L.at(i) = cstr;
        for (const auto &ch :L.at(i)) {
            L_convert.at(i) += B[ch];
        }
    }
    scanf("%s", cstr);
    string digits;
    for (int i = 0; cstr[i] != '\0'; ++i) {
        if (cstr[i] != '1') {
            digits.push_back(cstr[i]);
        }
    }

    int counter = 0;
    for (const auto &i : L_convert) {
        if (i == digits) {
            ++counter;
        }
    }
    printf("%d\n", counter);
    return 0;
}
