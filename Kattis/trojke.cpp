// https://open.kattis.com/problems/trojke
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

// Ax + By + C = 0
struct Line {
    int A, B, C;

    void simplify() {
        if (A < 0) {
            A = -A;
            B = -B;
            C = -C;
        }
        vector<int> nonZero;
        for (auto i : {A, B, C}) {
            if (i != 0) {
                nonZero.emplace_back(i);
            }
        }
        if (!nonZero.empty()) {
            int gcdTmp = accumulate(nonZero.begin(), nonZero.end(), nonZero[0],
                                    std::gcd<int, int>);
            A /= gcdTmp;
            B /= gcdTmp;
            C /= gcdTmp;
        }
    }

    Line(const pii &a, const pii &b) {
        A = a.second - b.second;
        B = b.first - a.first;
        C = a.first * b.second - b.first * a.second;
        simplify();
    }

    bool operator==(const Line &rhs) const {
        return A == rhs.A &&
               B == rhs.B &&
               C == rhs.C;
    }

    bool operator!=(const Line &rhs) const {
        return !(rhs == *this);
    }

};

struct my_hash_func {
    size_t operator()(const Line &obj) const {
        return hash<int>()(obj.A) ^ hash<int>()(obj.B) ^ hash<int>()(obj.C);
    }
};


inline
ostream &operator<<(std::ostream &os, const Line &v) {
    os << v.A << " " << v.B << " " << v.C;
    return os;
}

int n;
vector<vector<char> > M;
vector<pii> points;
gp_hash_table<Line, unordered_set<int>, my_hash_func> hashTable;

auto fast_io = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {

    fast_io();
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isalpha(M.at(i).at(j))) {
                points.emplace_back(i, j);
            }
        }
    }
    int length = static_cast<int>(points.size());
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            auto temp = Line(points.at(i), points.at(j));
            hashTable[temp].insert(
                    points.at(i).first * n + points.at(i).second);
            hashTable[temp].insert(
                    points.at(j).first * n + points.at(j).second);
        }
    }
    ll counter = 0;
    for (const auto &[k, v] : hashTable) {
        if (v.size() >= 3) {
            // C(v, 3)
            counter += v.size() * (v.size() - 1) * (v.size() - 2) / 6;
        }
    }
    cout << counter << '\n';
    return 0;
}
