// https://ac.nowcoder.com/acm/problem/15173

#include <iostream>
#include <string>

using namespace std;

int myAccumulate(const string &s)
{
    int res = 0;
    for (const auto &p : s) {
        res = res + static_cast<int>(p - '0');
    }
    return res;
}

int main()
{
    string n;
    cin >> n;
    while (n.size() != 1) {
        n = to_string(myAccumulate(n));
    }
    cout << n << endl;
    return 0;
}