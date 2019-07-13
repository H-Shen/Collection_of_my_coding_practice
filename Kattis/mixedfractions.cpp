// https://open.kattis.com/problems/mixedfractions
#include <iostream>

using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    ll a, b;
    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
        {
            break;
        }
        cout << a / b << " " << a % b << " / " << b << endl;
    }
    return 0;
}
