// https://open.kattis.com/problems/easiest

#include <iostream>

using namespace std;

inline
int sumOfDigit(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, p, currentSum;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        currentSum = sumOfDigit(n);
        p = 11;
        while (1)
        {
            if (currentSum == sumOfDigit(n * p))
            {
                cout << p << endl;
                break;
            }
            ++p;
        }
    }
    return 0;
}
