#include <bits/stdc++.h>

using namespace std;

int lowestTriangle(int base, int area){
    // Complete this function
    int temp = 2 * area;
    if (temp % base == 0) {
        return temp / base;
    }
    return static_cast<int>(temp / base) + 1;
}

int main() {
    int base;
    int area;
    cin >> base >> area;
    int height = lowestTriangle(base, area);
    cout << height << endl;
    return 0;
}

