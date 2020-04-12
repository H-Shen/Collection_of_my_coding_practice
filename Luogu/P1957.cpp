#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
std::vector<std::string> splitByChar(std::string s, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(s);
    std::string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

bool isalpha(const string &s) {
    for (const char &ch : s) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}

int main() {

    // input
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i;
    cin >> i;
    string temp;
    int a;
    int b;
    int c;
    string s;
    string op;
    string expr;
    bool flag;
    while (i--) {
        cin >> temp;
        if (isalpha(temp)) {
            cin >> a >> b;
            flag = true;
        } else {
            a = stoi(temp);
            cin >> b;
            flag = false;
        }
        if (flag) {
            op = temp;
            if (op == "a") {
                c = a + b;
                expr = to_string(a) + "+" + to_string(b) + "=" + to_string(c);
            }
            else if (op == "b") {
                c = a - b;
                expr = to_string(a) + "-" + to_string(b) + "=" + to_string(c);
            }
            else {
                c = a * b;
                expr = to_string(a) + "*" + to_string(b) + "=" + to_string(c);
            }
        } else {
            if (op == "a") {
                c = a + b;
                expr = to_string(a) + "+" + to_string(b) + "=" + to_string(c);
            }
            else if (op == "b") {
                c = a - b;
                expr = to_string(a) + "-" + to_string(b) + "=" + to_string(c);
            }
            else {
                c = a * b;
                expr = to_string(a) + "*" + to_string(b) + "=" + to_string(c);
            }
        }
        cout << expr << '\n';
        cout << expr.size() << '\n';
    }


    return 0;
}

