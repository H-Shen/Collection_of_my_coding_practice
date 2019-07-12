// https://open.kattis.com/problems/fizzbuzz
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int x, y, n;
    cin >> x >> y >> n;
    for (int i = 1; i <= n; ++i)
    {
        if (i % x == 0)
        {
            if (i % y == 0)
            {
                cout << "FizzBuzz" << endl;
            }
            else
            {
                cout << "Fizz" << endl;
            }
        }
        else if (i % y == 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}
