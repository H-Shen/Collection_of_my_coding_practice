// https://open.kattis.com/problems/measurement
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

// convert everything in th to other units
double convert2(ll n, const string &unit) {
    if (unit == "inch" || unit == "in") {
        return n * 1.0 / 1000.0;
    }
    else if (unit == "th" || unit == "thou") {
        return n * 1.0;
    }
    else if (unit == "ft" || unit == "foot") {
        return n * 1.0 / (12*1000);
    }
    else if (unit == "yd" || unit == "yard") {
        return n * 1.0 / (3*12*1000);
    }
    else if (unit == "ch" || unit == "chain") {
        return n * 1.0 / (22*3*12*1000);
    }
    else if (unit == "fur" || unit == "furlong") {
        return n * 1.0 / (22*3*12*1000*10);
    }
    else if (unit == "mi" || unit == "mile") {
        return n * 1.0 / (8*22*3*12*1000*10);
    }
    return n * 1.0 / (3*8*22*3*12*1000*10);
}

// convert everything to th
ll convert(ll n, const string& unit) {
    if (unit == "inch" || unit == "in") {
        return 1000*n;
    }
    else if (unit == "th" || unit == "thou") {
        return n;
    }
    else if (unit == "ft" || unit == "foot") {
        return 12*1000*n;
    }
    else if (unit == "yd" || unit == "yard") {
        return 3*12*1000*n;
    }
    else if (unit == "ch" || unit == "chain") {
        return 22*3*12*1000*n;
    }
    else if (unit == "fur" || unit == "furlong") {
        return 22*3*12*1000*10*n;
    }
    else if (unit == "mi" || unit == "mile") {
        return 8*22*3*12*1000*10*n;
    }
    return 3*8*22*3*12*1000*10*n;
}

int main() {

    ll v;
    string a, b, c;
    cin >> v >> a >> b >> c;
    printf("%.10lf\n", convert2(convert(v, a), c));

    return 0;
}
