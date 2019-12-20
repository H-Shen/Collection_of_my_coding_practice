// https://ac.nowcoder.com/acm/problem/15450

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        cout << count_if(begin(s), end(s), [](const char &a){return a == '7';}) << endl;
    }
    return 0;
}