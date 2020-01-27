// https://open.kattis.com/problems/lawnmower
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-8;
constexpr double MAX_LENGTH = 100.0;
constexpr double MAX_WIDTH = 75.0;

inline static
int sgn(const double &x) {
    if (x > EPS) {
        return 1;
    }
    if (x > -EPS) {
        return 0;
    }
    return -1;
}

struct Range {
    double middle;
    double lowerbound;
    double upperbound;
    Range(double middle, double width, bool y_axis) :
    middle(middle) {
        auto temp = width / 2.0;
        lowerbound = middle - temp;
        upperbound = middle + temp;
        if (y_axis) {
            lowerbound = clamp(lowerbound, 0.0, MAX_WIDTH);
            upperbound = clamp(upperbound, 0.0, MAX_WIDTH);
        } else {
            lowerbound = clamp(lowerbound, 0.0, MAX_LENGTH);
            upperbound = clamp(upperbound, 0.0, MAX_LENGTH);
        }
        this->middle = (lowerbound + upperbound) / 2.0;
    }
    Range() = default;
};

inline static
bool cmp(const Range &lhs, const Range &rhs) {
    return (sgn(lhs.middle - rhs.middle) < 0);
}

inline static
bool combine(const Range &lhs, const Range &rhs, Range &output, bool y_axis) {
    if (sgn(lhs.upperbound - rhs.lowerbound) >= 0 && sgn(lhs.lowerbound - rhs.upperbound) <= 0) {
        output.lowerbound = lhs.lowerbound;
        output.upperbound = rhs.upperbound;
        if (y_axis) {
            output.lowerbound = clamp(output.lowerbound, 0.0, MAX_WIDTH);
            output.upperbound = clamp(output.upperbound, 0.0, MAX_WIDTH);
        } else {
            output.lowerbound = clamp(output.lowerbound, 0.0, MAX_LENGTH);
            output.upperbound = clamp(output.upperbound, 0.0, MAX_LENGTH);
        }
        output.middle = (output.upperbound + output.lowerbound) / 2.0;
        return true;
    }
    return false;
}

inline static
bool check_summation(const Range &obj, bool y_axis) {
    if (y_axis) {
        return sgn(obj.lowerbound) == 0 && sgn(obj.upperbound - MAX_WIDTH) == 0;
    }
    return sgn(obj.lowerbound) == 0 && sgn(obj.upperbound - MAX_LENGTH) == 0;
}

inline static
bool valid_range(const Range &obj, bool y_axis) {
    if (y_axis) {
        return (sgn(obj.lowerbound) >= 0 && sgn(obj.upperbound - MAX_WIDTH) <= 0);
    } else {
        return (sgn(obj.lowerbound) >= 0 && sgn(obj.upperbound - MAX_LENGTH) <= 0);
    }
}

int main() {

    int n_x, n_y;
    double w, pos;

    while (true) {
        scanf("%d %d %lf", &n_x, &n_y, &w);
        if (n_x == 0 && n_y == 0 && sgn(w) == 0) {
            break;
        }
        deque<Range> X;
        for (int i = 0; i < n_x; ++i) {
            scanf("%lf", &pos);
            Range temp(pos, w, true);
            if (valid_range(temp, true)) {
                X.emplace_back(pos, w, true);
            }
        }
        deque<Range> Y;
        for (int i = 0; i < n_y; ++i) {
            scanf("%lf", &pos);
            Range temp(pos, w, false);
            if (valid_range(temp, false)) {
                Y.emplace_back(pos, w, false);
            }
        }
        Range output;
        Range a;
        Range b;
        // Check X
        if (X.empty()) {
            printf("NO\n");
            continue;
        } else {
            bool haveAns = true;
            sort(X.begin(), X.end(), cmp);
            while (X.size() > 1) {
                a = X.front();
                X.pop_front();
                b = X.front();
                X.pop_front();
                if (!combine(a, b, output, true)) {
                    haveAns = false;
                    break;
                } else {
                    X.push_front(output);
                }
            }
            if (!haveAns) {
                printf("NO\n");
                continue;
            } else {
                output = X.front();
                if (!check_summation(output, true)) {
                    printf("NO\n");
                    continue;
                }
            }
        }
        // Check Y
        if (Y.empty()) {
            printf("NO\n");
            continue;
        } else {
            bool haveAns = true;
            sort(Y.begin(), Y.end(), cmp);
            while (Y.size() > 1) {
                a = Y.front();
                Y.pop_front();
                b = Y.front();
                Y.pop_front();
                if (!combine(a, b, output, false)) {
                    haveAns = false;
                    break;
                } else {
                    Y.push_front(output);
                }
            }
            if (!haveAns) {
                printf("NO\n");
            } else {
                output = Y.front();
                if (!check_summation(output, false)) {
                    printf("NO\n");
                    continue;
                } else {
                    printf("YES\n");
                    continue;
                }
            }
        }

    }
    return 0;
}
