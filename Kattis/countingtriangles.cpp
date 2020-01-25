// https://open.kattis.com/problems/countingtriangles
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using PX = complex<double>;
using SEGMENT = pair<PX, PX>;

constexpr double EPS = 1e-9;

inline static
double cp(PX a, PX b) { return (conj(a) * b).imag(); }

inline static
int ccw(PX a, PX b, PX c) {
    double r = cp(b - a, c - a);
    if (fabs(r) < EPS) return 0;
    return r > 0 ? 1 : -1;
}

inline static
bool onSeg(PX p1, PX p2, PX x) {
    return fabs(abs(p2 - p1) - abs(x - p1) - abs(x - p2)) < EPS;
}

inline static
bool segIntersect(PX p1, PX p2, PX q1, PX q2) {
    int o1 = ccw(p1, p2, q1);
    int o2 = ccw(p1, p2, q2);
    int o3 = ccw(q1, q2, p1);
    int o4 = ccw(q1, q2, p2);
    if (o1 != o2 && o3 != o4) return true;
    // p1, p2 and q1 are colinear and q1 on p1p2
    if (o1 == 0 && onSeg(p1, p2, q1)) return true;
    // p1, p2 and q1 are colinear and q2 on p1p2
    if (o2 == 0 && onSeg(p1, p2, q2)) return true;
    // q1, q2 and p1 are colinear and p1 on q1q2
    if (o3 == 0 && onSeg(q1, q2, p1)) return true;
    // q1, q2 and p2 are colinear and p2 on q1q2
    if (o4 == 0 && onSeg(q1, q2, p2)) return true;
    return false; // Doesn’t fall in above cases
}

struct pair_hash {
    size_t operator () (const pair<int, int> &p) const {
        auto h1 = hash<int>{}(p.first);
        auto h2 = hash<int>{}(p.second);
        return h1 ^ h2;
    }
};

int main() {

    int n;
    double x1, y1, x2, y2;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<SEGMENT> A(n);
        for (auto &i : A) {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            i.first.real(x1);
            i.first.imag(y1);
            i.second.real(x2);
            i.second.imag(y2);
        }
        unordered_set<pair<int, int>, pair_hash> temp_hashset;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (segIntersect(A.at(i).first, A.at(i).second, A.at(j).first,
                                 A.at(j).second)) {
                    temp_hashset.insert(make_pair(i, j));
                }
            }
        }

        int counter = 0;
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // check if (i, j), (j, k), (i, k) all in temp_hashset
                    if (temp_hashset.find(make_pair(i, j)) !=
                        temp_hashset.end()) {
                        if (temp_hashset.find(make_pair(j, k)) !=
                            temp_hashset.end()) {
                            if (temp_hashset.find(make_pair(i, k)) !=
                                temp_hashset.end()) {
                                ++counter;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", counter);
    }

    return 0;
}
