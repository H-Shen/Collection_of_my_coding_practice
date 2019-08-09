// https://ac.nowcoder.com/acm/problem/14828

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int day = 0;
    cin >> n;

    int quot = n / 3;
    day = 2 * quot;
    if (n % 3 != 0) {
        ++day;
    }


    cout << day << endl;
    return 0;
}