#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    cin.get();
    string a;
    string r1;
    string r2;
    bool flag;
    while (T--) {
        getline(cin, a);
        int s = static_cast<int>(a.size());
        r1 = "";
        r2 = "";
        flag = true;
        while (s > 0) {
            if (flag) {
                r1.push_back(a.front());
                --s;
                a = a.substr(1);
                flag = false;
            } else {
                r2.push_back(a.front());
                --s;
                a = a.substr(1);
                flag = true;
            }
        }
        cout << r1 << ' ' << r2 << endl;
    }
    return 0;
}