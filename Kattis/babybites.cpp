// https://open.kattis.com/problems/babybites
#include <string>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        if (s != to_string(i) && s != "mumble")
        {
            cout << "something is fishy" << endl;
            return 0;
        }
    }
    cout << "makes sense" << endl;

    return 0;
}
