#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main() {

    string s;
    getline(cin, s);
    for (auto &i : s) {
        i = toupper(i);
    }
    cout << s << '\n';

    return 0;
}