// https://www.nowcoder.com/practice/54ef7fa64c63442d87b9c836ef9c7701

#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

class CTriangle {
private:
    ll x0, y0, x1, y1, x2, y2;
    bool isRightTriangle = false;
    double circumference;
public:
    CTriangle(ll x0_, ll y0_,
              ll x1_, ll y1_,
              ll x2_, ll y2_) : x0(x0_), y0(y0_),
                                x1(x1_), y1(y1_),
                                x2(x2_), y2(y2_) {

        // judge if it is a right triangle
        ll a = (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
        ll b = (x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2);
        ll c = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        ll A[3] = {a, b, c};
        sort(A, A + 3);
        if (A[0] + A[1] == A[2]) {
            isRightTriangle = true;
        }

        // calculate its circumference
        circumference = sqrt(a) + sqrt(b) + sqrt(c);
    }

    bool getIsRightTriangle() const {
        return isRightTriangle;
    }

    double getCircumference() const {
        return circumference;
    }
};

int main() {

    int m;
    ll x0, y0, x1, y1, x2, y2;
    cin >> m;
    while (m--) {
        cin >> x0 >> y0;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        auto temp = CTriangle(x0, y0, x1, y1, x2, y2);
        if (temp.getIsRightTriangle()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        printf("%.2lf\n", temp.getCircumference());
    }

    return 0;
}