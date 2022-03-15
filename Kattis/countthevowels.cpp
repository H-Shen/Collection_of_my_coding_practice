// https://open.kattis.com/problems/countthevowels

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    cout << count_if(s.begin(), s.end(), [](const char &ch){
        char c = toupper(ch);
        return c == 'A' || c == 'I' || c == 'E' || c == 'O' || c == 'U';
    });
    return 0;
}
