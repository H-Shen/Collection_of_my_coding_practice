#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int len;
    cin >> len;
    vector<int> a(len);
    for (int i = 0; i < len; i++)
        cin >> a[i];

    int pos, posA, posB;
    cin >> pos >> posA >> posB;
    a.erase(a.begin() + pos - 1);
    a.erase(a.begin() + posA - 1, a.begin() + posB - 1);

    len = static_cast<int>(a.size());
    cout << len << endl;
    for (int i = 0; i < len - 1; i++)
        cout << a[i] << ' ';
    cout << a[len - 1] << endl;

    return 0;
}
