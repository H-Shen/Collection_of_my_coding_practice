// https://www.nowcoder.com/practice/b5a1ceae9f884b6d8f0f798b93404b3d

#include <cmath>
#include <iostream>

using namespace std;

int main() {

    int m, a, b, c;
    cin >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (a == 0) {
            if (b == 0) {
                // Case 1
                if (c == 0) {
                    cout << "x=0.00" << endl;
                }
                    // Case 2
                else {
                    cout << -1 << endl;
                }
            }
                // Case 3
            else {
                printf("x=%.2lf\n", static_cast<double>((c * (-1.0)) / b));
            }
        } else {
            int delta = b * b - 4 * a * c;
            // Case 4
            if (delta < 0) {
                cout << -1 << endl;
            }
                // Case 5
            else if (delta == 0) {
                printf("x=%.2lf\n", static_cast<double>((-b) / (2.0 * a)));
            }
                // Case 6
            else {
                double x1 = (-b - sqrt(static_cast<double>(delta))) / (2.0 * a);
                double x2 = (-b + sqrt(static_cast<double>(delta))) / (2.0 * a);
                printf("x1=%.2lf,x2=%.2lf\n", x1, x2);
            }
        }
    }
    return 0;
}