// https://ac.nowcoder.com/acm/problem/14510

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout << a << b << endl;
    }
    return 0;
}