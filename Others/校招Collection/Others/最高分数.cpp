// https://www.nowcoder.com/practice/52c18a3b49a54fc98107fbdde1415f90
// Compiled in C++14(g++5.4)
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
     
    int a, b, c;
    while (cin >> a >> b >> c) {
        cout << max(a, max(b, c)) << endl;
    }
     
    return 0;
}