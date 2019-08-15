#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
char s[MAXN];

class Fraction {
public:

    void Simplify();

    void Display();

    Fraction operator+(const Fraction &f) const;

    Fraction operator-(const Fraction &f) const;

    int numerator = 1;
    int denominator = 1;
    bool isNegative = false;

    Fraction(int numerator, int denominator, bool isNegative) : numerator(numerator), denominator(denominator),
                                                                isNegative(isNegative) {};

    Fraction() = default;
};

int gcd(int a, int b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

void Fraction::Simplify() {
    if (numerator == 0 || denominator == 0) {
        return;
    }
    int Gcd = gcd(numerator, denominator);
    numerator /= Gcd;
    denominator /= Gcd;
}

Fraction Fraction::operator+(const Fraction &f) const {

    Fraction res;

    if (isNegative == f.isNegative) {
        res.isNegative = isNegative;
        res.denominator = denominator * f.denominator;
        res.numerator = numerator * f.denominator + denominator * f.numerator;
    } else {
        res.denominator = denominator * f.denominator;
        if (!isNegative && f.isNegative) {
            res.numerator = numerator * f.denominator - denominator * f.numerator;
        } else {
            res.numerator = denominator * f.numerator - numerator * f.denominator;
        }

        if (res.numerator < 0) {
            res.numerator *= -1;
            res.isNegative = true;
        }
    }

    res.Simplify();
    return res;
}

Fraction Fraction::operator-(const Fraction &f) const {

    Fraction f_copy = f;
    f_copy.isNegative = !f_copy.isNegative;

    Fraction res = (*this) + f_copy;
    res.Simplify();
    return res;
}

void Fraction::Display() {

    //2 EXCEPTIONS
    if (denominator == 0) {
        printf("Inf");
        return;
    } else if (numerator == 0) {
        printf("0");
        return;
    }

    string displayResult;
    if (denominator == 1) {
        displayResult = to_string(numerator);
    } else if (numerator > denominator) {
        displayResult = to_string(numerator / denominator) + ' ' + to_string(numerator % denominator) + '/' +
                        to_string(denominator);
    } else {
        displayResult = to_string(numerator) + '/' + to_string(denominator);
    }

    if (isNegative) {
        displayResult = "-" + displayResult;
    }

    printf("%s", displayResult.c_str());
}

Fraction generator(string &s) {

    Fraction res;
    if (s[0] == '-') {
        res.isNegative = true;
        s = s.substr(1);
    }

    size_t pos = s.find('/');
    int numerator = stoi(s.substr(0, pos));
    int denominator = stoi(s.substr(pos + 1));

    res.numerator = numerator;
    res.denominator = denominator;
    res.Simplify();

    return res;
}

int main() {

    int n, i;
    scanf("%d", &n);
    vector<Fraction> A(static_cast<unsigned long>(n));
    for (i = 0; i < n; ++i) {
        string f_str;
        scanf("%s", s);
        f_str = s;
        A[i] = generator(f_str);
    }

    Fraction Sum = accumulate(A.begin(), A.end(), Fraction(0, 1, false));
    Sum.Display();
    printf("\n");

    return 0;
}