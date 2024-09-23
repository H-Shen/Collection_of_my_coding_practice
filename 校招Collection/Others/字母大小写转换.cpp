// https://www.nowcoder.com/practice/850ebd30a2a34cfc87199da3fc15786a
// Compiled in C++14(g++5.4)
 
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    
    char ch;
    while (cin >> ch) {
        cin.get();
        if (isupper(ch)) {
            cout << static_cast<char>(tolower(ch));
        } else {
            cout << static_cast<char>(toupper(ch));
        }
        cout << endl;
    }
     
    return 0;
}