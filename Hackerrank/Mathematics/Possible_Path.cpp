#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 1.gcd(a + m*b, b) = gcd(a, b).
// 2.gcd(a,b) = gcd(a+b,b) = gcd(a,a+b) = gcd(a-b,b) = gcd(a,a-b).
// 3.If we make several moves, then it can be seen that we can ONLY visit points whose coordinates have the same gcd.
// 4.All moves are reversible (through one or more "reversal" moves). Like this:
// 5.Every point (a, b) can be routed to point (gcd(a,b), gcd(a,b)). This is because the moves (subtractions) made by Euclid's Algorithm (subtraction method) can be simulated by using the operations presented in the problem.
// So if two points (a,b) and (x,y) can be routed to the same gcd point, then they are connected.

typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll a, b, x, y;
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> x >> y;
        if (__gcd(a, b) == __gcd(x, y)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
