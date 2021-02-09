int Gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    int t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    Point() : Point(0, 0) {}
    string toString() const {
        return std::to_string(x) + " " + std::to_string(y);
    }
};

// Ax + By + C = 0
struct Line {
    int A, B, C;
    Line(const Point &a, const Point &b) {
        A = a.y - b.y;
        B = b.x - a.x;
        C = a.x*b.y-b.x*a.y;
        simplify();
    }
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
            int gcdTmp = accumulate(nonZero.begin(), nonZero.end(), nonZero[0], Gcd);
            A /= gcdTmp;
            B /= gcdTmp;
            C /= gcdTmp;
        }
    }
    bool onLine(const Point &a) const {
        return A*a.x+B*a.y+C == 0;
    }
    string toString() const {
        return std::to_string(A) + " " + std::to_string(B) + " " + std::to_string(C);
    }
};

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() <= 2) return true;
        Point u(coordinates[0][0], coordinates[0][1]);
        Point v(coordinates[1][0], coordinates[1][1]);
        Line l(u, v);
        int n = (int)coordinates.size();
        for (int i = 2; i < n; ++i) {
            if (!l.onLine(Point(coordinates[i][0], coordinates[i][1]))) {
                return false;
            }
        }
        return true;
    }
};