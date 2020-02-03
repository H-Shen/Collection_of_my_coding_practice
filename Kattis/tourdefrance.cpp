// https://open.kattis.com/problems/tourdefrance
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
vector<int> splitByChar(string s, const char &delim) {
    vector<int> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(stoi(s));
    }
    return res;
}

int main() {
    
    string s;
    int f;
    int r;
    while (true) {
        getline(cin, s);
        if (s == "0") {
            break;
        }
        auto p = splitByChar(s, ' ');
        f = p.at(0);
        r = p.at(1);
        vector<int> Front(f);
        for (auto &i : Front) {
            cin >> i;
        }
        vector<int> Rear(r);
        for (auto &i : Rear) {
            cin >> i;
        }
        vector<double> A;
        for (const auto &i : Rear) {
            for (const auto &j : Front) {
                A.emplace_back(i * 1.0 / j);
            }
        }
        double maximal_spread = 0.0;
        if (!A.empty()) {
            sort(A.begin(), A.end());
            int n = static_cast<int>(A.size());
            for (int i = 0; i < n - 1; ++i) {
                maximal_spread = max(maximal_spread, A.at(i + 1) / A.at(i));
            }
        }
        printf("%.2lf\n", maximal_spread);
        cin.get();
    }
    
    return 0;
}
