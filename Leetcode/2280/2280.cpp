using ll = long long;

inline
ll Gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    ll t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

struct Point {
    ll x, y;
    Point(ll x, ll y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
};

// Ax + By + C = 0
struct Line {
    ll A, B, C;
    Line(const Point &a, const Point &b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = a.x*b.y-b.x*a.y;
        simplify();
    }
    bool onLine(const Point &c) const {
        return A*c.x+B*c.y+C == 0;
    }
    void simplify() {
        if (A < 0) {
            A = -A;
            B = -B;
            C = -C;
        }
        vector<ll> nonZero;
        for (auto i : {A, B, C}) {
            if (i != 0) {
                nonZero.emplace_back(i);
            }
        }
        if (!nonZero.empty()) {
            ll gcdTmp = accumulate(nonZero.begin(), nonZero.end(), nonZero[0], Gcd);
            A /= gcdTmp;
            B /= gcdTmp;
            C /= gcdTmp;
        }
    }
};

class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(),stockPrices.end(),[](const auto &l, const auto &r){
            return l[0] < r[0];
        });
        int counter = 0;
        int n = (int)stockPrices.size();
        if (n == 2) {
            ++counter;
        }
        else if (n > 2) {
            Point a(stockPrices[0][0], stockPrices[0][1]);
            Point b(stockPrices[1][0], stockPrices[1][1]);
            ++counter;
            Line line(Point(stockPrices[0][0], stockPrices[0][1]), b);
            Point c, temp;
            for (int i = 2; i < n; ++i) {
                c.x = stockPrices[i][0];
                c.y = stockPrices[i][1];
                temp = b;
                b = c;
                a = temp;
                if (!line.onLine(c)) {
                    Line newLine(a, b);
                    swap(line, newLine);
                    ++counter;
                }
            }
        }
        return counter;
    }
};