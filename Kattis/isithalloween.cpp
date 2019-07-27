// https://open.kattis.com/problems/isithalloween
#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    if (s == "OCT 31" || s == "DEC 25") {
        cout << "yup" << endl;
    } else {
        cout << "nope" << endl;
    }
    return 0;
}
