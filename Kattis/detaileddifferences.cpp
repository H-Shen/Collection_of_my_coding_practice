// https://open.kattis.com/problems/detaileddifferences
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string a, b;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        cout << a << endl;
        cout << b << endl;
        string tmp (a.size(), ' ');
        for (size_t j = 0; j < a.size(); ++j)
        {
            if (a[j] != b[j])
            {
                tmp[j] = '*';
            }
            else
            {
                tmp[j] = '.';
            }
        }
        cout << tmp << endl << endl;
    }
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    string tmp (a.size(), ' ');
    for (size_t j = 0; j < a.size(); ++j)
    {
        if (a[j] != b[j])
        {
            tmp[j] = '*';
        }
        else
        {
            tmp[j] = '.';
        }
    }
    cout << tmp << endl;
    return 0;
}
