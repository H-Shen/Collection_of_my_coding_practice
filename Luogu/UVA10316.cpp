#include <bits/stdc++.h>

using namespace std;

constexpr double eps = 1e-7;
inline static
int sgn(double x) {
    if (x > eps) return 1;
    if (x > -eps) return 0;
    return -1;
}

inline static
double gcDistance(double pLat, double pLong, double qLat, double qLong) {
    pLat = pLat * M_PI / 180.0;
    pLong = pLong * M_PI / 180.0;
    qLat = qLat * M_PI / 180.0;
    qLong = qLong * M_PI / 180.0;
    return acos(cos(pLat) * cos(pLong) * cos(qLat) * cos(qLong) +
                cos(pLat) * sin(pLong) * cos(qLat) * sin(qLong) +
                sin(pLat) * sin(qLat));
}

struct Node {
    double Lat, Long;
};

int main() {

    int n;
    while (~scanf("%d", &n)) {
        vector<Node> A(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &A.at(i).Lat, &A.at(i).Long);
        }
        double dist;
        vector<double> maximum_direct_flying_distance(n, -1.0);
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dist = gcDistance(A.at(i).Lat, A.at(i).Long, A.at(j).Lat, A.at(j).Long);
                maximum_direct_flying_distance.at(i) = max(maximum_direct_flying_distance.at(i), dist);
                maximum_direct_flying_distance.at(j) = max(maximum_direct_flying_distance.at(j), dist);
            }
        }
        double min_val = *min_element(maximum_direct_flying_distance.begin(), maximum_direct_flying_distance.end());
        for (int i = n - 1; i >= 0; --i) {
            if ( sgn(maximum_direct_flying_distance.at(i) - min_val) == 0 ) {
                printf("%.2lf %.2lf\n", A.at(i).Lat, A.at(i).Long);
                break;
            }
        }
    }

    return 0;
}
