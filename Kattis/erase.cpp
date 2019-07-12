// https://open.kattis.com/problems/erase
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string a, b, c;
    cin >> n >> a >> b;
    if (n % 2 == 0)
    {
        if (a == b) cout << "Deletion succeeded" << endl;
        else cout << "Deletion failed" << endl;
    }
    else
    {
        c = a;
        for (size_t i = 0; i < a.size(); ++i)
        {
            if (a[i] == '1') c[i] = '0';
            else c[i] = '1';
        }
        if (b == c) cout << "Deletion succeeded" << endl;
        else cout << "Deletion failed" << endl;
    }
    return 0;
}
