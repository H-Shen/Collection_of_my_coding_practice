// https://www.nowcoder.com/practice/071f1acaada4477f94193f8c0b9054f4

#include <cmath>
#include <cctype>

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

void operate(string str, int &a, int &b, int &c) {
    int len = static_cast<int>(str.size());
    for (int i = 0; i < len; i++) {
        if (str[i] == '+' || str[i] == '-')
            continue;
        else if (str[i] == 'x') {
            if (i + 1 < len && str[i + 1] == '^') {
                if (i - 1 >= 0 && str[i - 1] == '-')
                    --a;
                else
                    ++a;
                i += 2;
            } else {
                if (i - 1 >= 0 && str[i - 1] == '-')
                    --b;
                else
                    ++b;
            }
        } else {
            int temp_sum = 0;
            int j = i;
            while (isdigit(str[i])) {
                temp_sum = temp_sum * 10 + str[i] - '0';
                i++;
            }
            if (j - 1 >= 0 && str[j - 1] == '-')
                temp_sum = 0 - temp_sum;
            if (i < len && str[i] == 'x') {
                if (i + 1 < len && str[i + 1] == '^') {
                    a = a + temp_sum;
                    i = i + 2;
                } else {
                    b = b + temp_sum;
                }
            } else
                c = c + temp_sum;
        }
    }
}

int main() {
    string str;
    while (cin >> str) {
        int j = 0;
        int len = static_cast<int>(str.size());
        for (int i = 0; i < len; i++) {
            if (str[i] == '=')
                j = i;
        }
        string str_left, str_right;
        str_left = str.substr(0, static_cast<unsigned long>(j));
        str_right = str.substr(static_cast<unsigned long>(j) + 1);
        int a1 = 0, b1 = 0, c1 = 0;
        int a2 = 0, b2 = 0, c2 = 0;
        operate(str_left, a1, b1, c1);
        operate(str_right, a2, b2, c2);
        int a = a1 - a2;
        int b = b1 - b2;
        int c = c1 - c2;
        int temp = b * b - 4 * a * c;
        if (temp < 0)
            cout << "No Solution" << endl;
        else {
            double x1, x2;
            x1 = (0 - b + sqrt(temp)) / (2 * a);
            x2 = (0 - b - sqrt(temp)) / (2 * a);
            if (x1 < x2)
                cout << fixed << setprecision(2) << x1 << " " << x2 << endl;
            else
                cout << fixed << setprecision(2) << x2 << " " << x1 << endl;
        }
    }
    return 0;
}