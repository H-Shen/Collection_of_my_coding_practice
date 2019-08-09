// https://ac.nowcoder.com/acm/problem/14831

#include <iostream>
#include <string>

using namespace std;

using ll = long long;
const string::size_type maxn = 1050;

int main()
{
    string s;
    ll n = 1;
    while (s.size() < maxn) {
        s += to_string(n);
        ++n;
    }
    int i;
    cin >> i;
    cout << s.at(i - 1) << endl;

    return 0;
}