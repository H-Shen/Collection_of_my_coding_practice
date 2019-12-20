// https://ac.nowcoder.com/acm/problem/15531

#include <iostream>

using namespace std;

int main()
{
    int h, m, n, tmp;
    cin >> n;
    while (n--)
    {
        h = 12;
        m = 0;
        cin >> tmp;
        h = h + tmp / 60;
        m = tmp % 60;

        cout << h << ":";
        if (m < 10) cout << '0';
        cout << m << endl;
    }

    return 0;

}