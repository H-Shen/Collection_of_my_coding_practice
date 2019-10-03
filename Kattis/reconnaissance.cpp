// https://open.kattis.com/problems/reconnaissance
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline static
double getDistance(const pair<ll, ll> &vehicle, const double &time) {
    return vehicle.first + vehicle.second * time;
}

inline static
double getMaxDistanceBetweenTwoVehicle(const vector<pair<ll, ll> > &vehicles, const double &time) {
    bool firstItem = true;
    double minVal = 0.0;
    double maxVal = minVal;
    double tempVal;
    for (const auto &i : vehicles) {
        tempVal = getDistance(i, time);
        if (firstItem) {
            firstItem = false;
            minVal = tempVal;
            maxVal = tempVal;
        } else {
            minVal = min(minVal, tempVal);
            maxVal = max(maxVal, tempVal);
        }
    }
    return maxVal - minVal;
}

int main() {

    int n;
    scanf("%d", &n);

    // pair<position, velocity>
    vector<pair<ll, ll> > A(static_cast<int>(n));
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld", &A.at(i).first, &A.at(i).second);
    }

    double l = 0.0;
    double r = 1000000.0;
    double eps = 1e-6;

    while (r - l > eps) {

        double r_mid = (l + r + r) / 3.0;
        double l_mid = (l + l + r) / 3.0;

        if (getMaxDistanceBetweenTwoVehicle(A, l_mid) < getMaxDistanceBetweenTwoVehicle(A, r_mid)) {
            r = r_mid;
        } else {
            l = l_mid;
        }
    }

    printf("%.4f\n", getMaxDistanceBetweenTwoVehicle(A, l));

    return 0;
}
