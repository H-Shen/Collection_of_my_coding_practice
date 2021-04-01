// Ax + By + C = 0
struct Line {
    int A, B, C;
    Line(const pair<int,int> &a, const pair<int,int> &b) {
        A = a.second - b.second;
        B = b.first - a.first;
        C = a.first*b.second-b.first*a.second;
        simplify();
    }
    void simplify() {
        if (A < 0) {
            A = -A;
            B = -B;
            C = -C;
        }
        vector<int> vec;
        if (A != 0) vec.emplace_back(A);
        if (B != 0) vec.emplace_back(B);
        if (C != 0) vec.emplace_back(C);
        if (vec.empty()) return;
        int temp;
        for (size_t i = 0; i != vec.size(); ++i) {
            if (i == 0) {
                temp = vec.at(i);
                continue;
            }
            temp = gcd(temp, vec.at(i));
        }
        
        A /= temp;
        B /= temp;
        C /= temp;
    }
    bool operator == (const Line &other) const {
        return A == other.A && B == other.B && C == other.C;
    } 
};

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto p0 = make_pair(points[0][0], points[0][1]);
        auto p1 = make_pair(points[1][0], points[1][1]);
        auto p2 = make_pair(points[2][0], points[2][1]);
        if (p0 == p1 || p1 == p2 || p0 == p2) return false;
        Line l0(p0, p1);
        Line l1(p1, p2);
        Line l2(p0, p2);
        if (l0 == l1 || l0 == l2 || l1 == l2) return false;
        return true;
    }
};