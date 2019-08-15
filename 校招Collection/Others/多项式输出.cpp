// https://ac.nowcoder.com/acm/contest/237/D

#include <bits/stdc++.h>

using namespace std;

class Item {
private:
    int coeff;
    int degree;
    bool firstItem;
public:
    Item(int coeff, int degree, bool firstItem) : coeff(coeff), degree(degree), firstItem(firstItem) {}
    string toString() const {

        string result;
        if (coeff == 0) {
            return result;
        }

        // handle sign
        if (firstItem) {
            if (coeff < 0) {
                result.push_back('-');
            }
        } else {
            if (coeff < 0) {
                result.push_back('-');
            } else {
                result.push_back('+');
            }
        }

        // handle coeff
        if (abs(coeff) != 1 || (abs(coeff) == 1 && degree == 0)) {
            result.append(to_string(abs(coeff)));
        }
        // handle degree (1, >1, 0)
        if (degree == 1) {
            result.push_back('x');
        } else if (degree > 1) {
            result.append("x^");
            result.append(to_string(degree));
        }
        return result;
    }
};

int main() {

    int n;
    int coeff;
    scanf("%d", &n);
    ++n;
    vector<Item> A;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &coeff);
        A.emplace_back(Item(coeff, n - i - 1, i == 0));
    }
    for (int i = 0; i < n; ++i) {
        printf("%s", A[i].toString().c_str());
    }
    printf("\n");

    return 0;
}