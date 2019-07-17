#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, temp, i;
    vector<int> a;
    cin >> n;
    while (n--) {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    int len = (int)a.size();
    for (i = 0; i < len - 1; i++)
        cout << a[i] << ' ';
    cout << a[len - 1] << endl;
    return 0;
}
