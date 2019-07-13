// https://open.kattis.com/problems/quadrant
#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0) cout << 1;
    else if (x > 0 && y < 0) cout << 4;
    else if (x < 0 && y < 0) cout << 3;
    else cout << 2;

    cout << endl;
    return 0;
}
