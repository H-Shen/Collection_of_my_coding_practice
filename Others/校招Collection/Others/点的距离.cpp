// https://www.nowcoder.com/practice/3468bd027c5a410e895150b0d5b13502

#include <cmath>
#include <iostream>

using namespace std;

class CPoint {
private:
    int x, y;
public:
    explicit CPoint(int x_, int y_) : x(x_), y(y_) {}

    double operator-(CPoint const &obj) const {
        int temp = (x - obj.x) * (x - obj.x) + (y - obj.y) * (y - obj.y);
        return sqrt(static_cast<double>(temp));
    }
};

int main() {

    int m, x0, y0, x1, y1;
    cin >> m;
    while (m--) {
        cin >> x0 >> y0 >> x1 >> y1;
        CPoint obj0 = CPoint(x0, y0);
        CPoint obj1 = CPoint(x1, y1);
        printf("%.2lf\n", obj0 - obj1);
    }
    return 0;
}