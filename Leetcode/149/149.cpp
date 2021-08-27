// 2019-07-08

struct Point {
    long long x;
    long long y;

    Point() : x(0), y(0) {}

    Point(long long a, long long b) : x(a), y(b) {}
};


long long Gcd(long long a, long long b) {

    a = abs(a);
    b = abs(b);
    long long t;

    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

struct Line {

    //Ax + By == C
    long long A, B, C;

    Line() = default;;

    Line(const Point &p1, const Point &p2) {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = A * p1.x + B * p1.y;
        simplify();
    }

    void simplify() {
        if (A < 0) {
            A = -A;
            B = -B, C = -C;
        }
        vector<long long> nonZero;
        for (auto i : {A, B, C}) {
            if (i != 0) {
                nonZero.push_back(i);
            }
        }
        if (!nonZero.empty()) {
            int gcdTmp = accumulate(nonZero.begin(), nonZero.end(), nonZero[0], Gcd);
            A /= gcdTmp;
            B /= gcdTmp;
            C /= gcdTmp;
        }
    }
};

struct hashCalcPoint {
    size_t operator()(const Point &p) const {
        return ((hash<int>()(p.x) ^ (hash<int>()(p.y) << 1)) >> 1);
    }
};

bool operator==(const Point &p1, const Point &p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}

bool operator==(const Line &L1, const Line &L2) {
    return (L1.A * L2.B == L2.A * L1.B
            && L1.A * L2.C == L2.A * L1.C
            && L1.B * L2.C == L2.B * L1.C);
}

struct hashCalcLine {
    size_t operator()(const Line &key) const {
        return ((hash<long long>()(key.A)
                 ^ (hash<long long>()(key.B) << 1)))
               ^ (hash<long long>()(key.C) << 1);
    }
};

class Solution {
public:
    int maxPoints(vector <vector<int>> &points_) {

        vector <Point> points(points_.size());
        for (size_t m = 0; m != points.size(); ++m) {
            points[m] = Point(points_[m][0], points_[m][1]);
        }

        int n = points.size();
        int i, j;
        //stats of all points in an unordered map
        unordered_map<Point, long long, hashCalcPoint> pointsStats;
        for (i = 0; i < n; i++) {
            ++pointsStats[points[i]];
        }

        //unique points
        unordered_set <Point, hashCalcPoint> uniquePoints(points.begin(), points.end());
        vector <Point> uPoints(uniquePoints.begin(), uniquePoints.end());
        n = uPoints.size();

        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return pointsStats[uPoints[0]];
        }

        unordered_map <Line, unordered_set<Point, hashCalcPoint>, hashCalcLine> LineCollection;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {

                Line tmp(uPoints[i], uPoints[j]);
                LineCollection[tmp].insert(uPoints[i]);
                LineCollection[tmp].insert(uPoints[j]);
            }
        }
        int maxCnt = -1;
        int pointCnt;

        for (auto &it0 : LineCollection) {

            pointCnt = 0;
            for (auto it1 : it0.second) {
                pointCnt = pointCnt + pointsStats[it1];
            }

            maxCnt = max(pointCnt, maxCnt);
        }
        return maxCnt;
    }
};