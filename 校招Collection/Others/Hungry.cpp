// https://ac.nowcoder.com/acm/problem/14745

#include <string>
#include <iostream>
#include <numeric>
#include <functional>

using namespace std;

string s = "gu...";

int main()
{
    int n, i;
    while (cin >> n) {
        string res;
        for (i = 0; i < n; ++i) {
            res += s;
        }
        cout << res << endl;
        cout << "The story is so boring. And I am so hungry!" << endl;
    }

    return 0;
}