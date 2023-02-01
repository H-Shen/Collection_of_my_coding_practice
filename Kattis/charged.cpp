#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
constexpr double EPS = 1e-6;
const double PI = acos(-1.0);
int sgn(const double& x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}
struct Node {
    int x, y;
    bool positive;
    Node() = default;
    Node(int x, int y, bool positive) : x(x), y(y), positive(positive) {}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    string temp;
    vector<vector<char>> A(n, vector<char>(m, '.'));
    vector<Node> vec(q);
    for (int i = 0; i < q; ++i) {
        cin >> vec[i].x >> vec[i].y >> temp;
        --vec[i].x;
        --vec[i].y;
        if (temp[0] == '+') {
            vec[i].positive = true;
            A[vec[i].y][vec[i].x] = '+';
        }
        else {
            vec[i].positive = false;
            A[vec[i].y][vec[i].x] = '-';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (A[i][j] == '.') {
                double s = 0;
                for (int k = 0; k < q; ++k) {
                    double dist = sqrt((vec[k].x - j) * (vec[k].x - j) + (vec[k].y - i) * (vec[k].y - i));
                    if (vec[k].positive) {
                        s += 1.0 / dist;
                    }
                    else {
                        s -= 1.0 / dist;
                    }
                }
                if (sgn(s) > 0) {
                    if (sgn(s - 1.0 / PI) > 0) {
                        A[i][j] = '0';
                    }
                    else if (sgn(s - 1.0 / (PI * PI)) > 0) {
                        A[i][j] = 'O';
                    }
                    else if (sgn(s - 1.0 / (PI * PI * PI)) > 0) {
                        A[i][j] = 'o';
                    }
                }
                else if (sgn(s) < 0) {
                    s = abs(s);
                    if (sgn(s - 1.0 / PI) > 0) {
                        A[i][j] = '%';
                    }
                    else if (sgn(s - 1.0 / (PI * PI)) > 0) {
                        A[i][j] = 'X';
                    }
                    else if (sgn(s - 1.0 / (PI * PI * PI)) > 0) {
                        A[i][j] = 'x';
                    }
                }
            }
        }
    }
    for (auto& i : A) {
        for (auto& j : i) {
            cout << j;
        }
        cout << '\n';
    }
    return 0;
}
