#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int m;
string s;

struct Node {
    explicit Node(int a, int b) : a(a), b(b) {}
    int a, b;
    string to_string() const {
        if (a == 0) return "";
        return "+" + ::to_string(a) + "*" + ::to_string(m) + "^" + ::to_string(b);
    }
};

int main() {

    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> m >> s;
    int length = static_cast<int>(s.size());
    vector<Node> A;
    for (int i = 0; i < length; ++i) {
        A.emplace_back(Node(s.at(i) - '0', length - 1 - i));
    }
    string result;
    for (const auto &i : A) {
        result += i.to_string();
    }
    if (result.empty()) {
        result = "0";
    } else if (result.front() == '+' && result.size() > 1) {
        result = result.substr(1);
    }
    cout << result << '\n';

    return 0;
}
