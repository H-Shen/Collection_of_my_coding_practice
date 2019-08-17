// https://www.nowcoder.com/practice/bd9eb2b825894da6acfca0951cc38220

/*
struct Point {
    int x;
    int y;
    Point() :
            x(0), y(0) {
    }
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
};*/

#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

struct Fraction {

    double getVal() const {

        //MAKE SURE THE DENOMINATOR NEVER EQUALS TO 0
        double res = x / y;
        if (isNegative) {
            res = res * (-1);
        }
        return res;
    }

    void Simplify() {
        if (x == 0) {
            return;
        }
        int Gcd = gcd(x, y);
        x /= Gcd;
        y /= Gcd;
    }

    int x = 1;
    int y = 1;
    bool isNegative = false;
};

struct Line {

    Fraction k;
    Fraction b;

    Line () {};
    Line (const Point &A, const Point &B) {

        int delta_x = 0, delta_y = 0;

        //K
        if (A.y == B.y) {
            k.x = 0;
            b.y = 1;
            if (A.y < 0) {
                b.isNegative = true;
                b.x = (-1) * A.y;
            }
            else {
                b.x = A.y;
            }
        }
        else {
            delta_x = B.x - A.x;
            delta_y = B.y - A.y;
            if (delta_x * delta_y < 0) {
                k.isNegative = true;
                k.x = abs(delta_y);
                k.y = abs(delta_x);
            }
            else {
                k.x = delta_y;
                k.y = delta_x;
            }
            k.Simplify();
        }

        //B
        int delta_tmp = A.y * B.x - B.y * A.x;
        if (delta_tmp * delta_x < 0) {
            b.isNegative = true;
            b.x = abs(delta_tmp);
            b.y = abs(delta_x);
        }
        else {
            b.x = delta_tmp;
            b.y = delta_x;
        }
        b.Simplify();
    }
};

struct hashCalc {
    size_t operator()(const Line &key) const {

        return ((hash<int>()(key.k.x)
            ^   (hash<int>()(key.k.y) << 1)) >> 1)
            ^   (hash<int>()(key.b.x) << 1);
    }
};

bool operator == (Fraction self, Fraction other) {
    other.Simplify();
    self.Simplify();
    if (self.x == other.x && self.y == other.y && self.isNegative == other.isNegative) {
        return true;
    }
    return false;
}

struct cmp {
    bool operator () (const Line &self, const Line &other) const {
        return self.k == other.k
            && self.b == other.b;
    }
};

class DenseLine {
public:
    vector<double> getLine(vector<Point> p, int n) {

        unordered_map <Line, int, hashCalc, cmp> LineCollection;
        vector <double> res;

        int i, j;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                Line tmp (p[i], p[j]);
                if (LineCollection.find(tmp) == LineCollection.end()) {
                    LineCollection[tmp] = 1;
                }
                else {
                    LineCollection[tmp]++;
                }
            }
        }

        int maxCnt = -1;
        for (auto it = LineCollection.begin(); it != LineCollection.end(); ++it) {
            if (it->second > maxCnt) {
                maxCnt = it->second;
            }
        }
        for (auto it = LineCollection.begin(); it != LineCollection.end(); ++it) {
            if (it->second == maxCnt) {
                res.push_back((it->first).k.getVal());
                res.push_back((it->first).b.getVal());
            }
        }
        return res;
    }
};