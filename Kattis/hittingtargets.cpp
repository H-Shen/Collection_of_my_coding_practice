// https://open.kattis.com/problems/hittingtargets
//
#include <bits/extc++.h>

using namespace std;

struct Rec {
    int x1, y1, x2, y2;
};
struct Circle {
    int x, y, r, r_sq;
};

vector<Rec> recList;
vector<Circle> circleList;

int main() {

    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    string s;
    while (m--) {
        cin >> s;
        if (s == "rectangle") {
            Rec temp{};
            cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
            recList.emplace_back(temp);
        } else {
            Circle temp{};
            cin >> temp.x >> temp.y >> temp.r;
            temp.r_sq = temp.r * temp.r;
            circleList.emplace_back(temp);
        }
    }

    int n, x, y, counter;
    cin >> n;
    while (n--) {
        cin >> x >> y;
        counter = 0;
        for (const auto &i : recList) {
            if (x >= i.x1 && x <= i.x2 && y >= i.y1 && y <= i.y2) {
                ++counter;
            }
        }
        for (const auto &i : circleList) {
            if ((x - i.x)*(x - i.x)+(y - i.y)*(y - i.y) <= i.r_sq) {
                ++counter;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
