#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    unordered_set<char> uniq;
    getline(cin, a);
    getline(cin, b);
    for (const char ch : a) {
        if (uniq.find(ch) == uniq.end()) {
            uniq.insert(ch);
            cout << ch;
        }
    }
    for (const char ch : b) {
        if (uniq.find(ch) == uniq.end()) {
            uniq.insert(ch);
            cout << ch;
        }
    }
    cout << endl;
    return 0;
}