// https://open.kattis.com/problems/zamka

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int l, d, x;
    cin >> l >> d >> x;

    int maxVal = -1;
    int minVal = 10005;
    int sum = 0;

    for (int i = l, i_copy = l; i <= d; ++i)
    {
        sum = 0;
        i_copy = i;
        while (i_copy > 0)
        {
            sum += i_copy % 10;
            i_copy /= 10;
        }
        if (sum == x)
        {
            if (i > maxVal)
            {
                maxVal = i;
            }
            if (i < minVal)
            {
                minVal = i;
            }
        }
    }
    cout << minVal << endl;
    cout << maxVal << endl;

    return 0;
}
