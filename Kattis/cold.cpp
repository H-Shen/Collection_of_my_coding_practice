// https://open.kattis.com/problems/cold
#include <iostream>

using namespace std;

int main()
{
    int n, temp;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (temp < 0) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
