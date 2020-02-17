#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    auto is_prime = [](int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    };
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        cout << (is_prime(val) ? "Prime" : "Not prime") << endl;
    }
    return 0;
}
