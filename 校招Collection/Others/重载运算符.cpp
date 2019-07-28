// https://www.nowcoder.com/practice/7b1e4ffc39604be3b15959ce329da490

#include <cmath>
#include <iostream>

using namespace std;

const double PI = acos(-1.0);

class Angle {
private:
    int deg;
public:
    explicit Angle(int deg_) : deg(deg_) {
        while (deg > 360) {
            deg -= 360;
        }
        while (deg < -360) {
            deg += 360;
        }
    }

    Angle operator-(Angle const &obj) const {
        return Angle(deg - obj.deg);
    }

    double getSine() const {
        return sin(deg * PI / 180.0);
    }
};

int main() {

    int m, val0, val1;
    cin >> m;
    while (m--) {
        cin >> val0 >> val1;
        auto obj0 = Angle(val0);
        auto obj1 = Angle(val1);
        obj0 = obj0 - obj1;
        printf("%.2lf\n", obj0.getSine());
    }

    return 0;
}