#include <bits/stdc++.h>

using namespace std;

int main(){
    string S;
    cin >> S;
    try {
        cout << stoll(S) << endl;
    } catch (...) {
        cout << "Bad String" << endl;
    }
    return 0;
}

