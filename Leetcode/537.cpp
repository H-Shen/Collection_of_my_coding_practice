class Solution {
public:
    string complexNumberMultiply(string a, string b) {

        struct Complex {
            long long a, b;

            [[nodiscard]] string toString() const {
                return to_string(a) + "+" + to_string(b) + "i";
            }

            Complex operator*(const Complex &B) {
                Complex res{};
                res.a = a * B.a - b * B.b;
                res.b = a * B.b + b * B.a;
                return res;
            }

            static Complex convert(string s) {
                Complex res{};
                stringstream ss(s);
                string item;
                int cnt = 1;
                while (getline(ss, item, '+')) {
                    if (cnt == 1) {
                        res.a = stol(item);
                        ++cnt;
                    } else {
                        item.pop_back();
                        res.b = stol(item);
                    }
                }
                return res;
            }
        };

        Complex A = Complex::convert(a) * Complex::convert(b);
        return A.toString();
    }
};