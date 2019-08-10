// https://ac.nowcoder.com/acm/problem/14518

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    string s;
    while (T--) {
        cin >> s;
        if ( s == string(s.crbegin(), s.crend()) ) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}