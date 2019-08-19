#include <bits/stdc++.h>

using namespace std;
const regex r0("6{10,}");
const regex r1("6{4,}");

int main() {
    ios_base::sync_with_stdio(false);
    string text;
    getline(cin, text);
    string s = regex_replace(regex_replace(text, r0, "27"), r1, "9");
    cout << s << endl;
}