// https://ac.nowcoder.com/acm/problem/15056

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time
{
    int x, y, z;
};

bool cmp(const Time &a, const Time &b)
{
    if (a.x == b.x) {
        if (a.y == b.y) {
            return (a.z < b.z);
        }
        return (a.y < b.y);
    }
    return (a.x < b.x);
}

int main()
{
    int n, i;
    cin >> n;
    vector <Time> A(n);
    for (i = 0; i < n; ++i) {
        cin >> A[i].x >> A[i].y >> A[i].z;
    }
    sort(A.begin(), A.end(), cmp);
    for (const auto &p : A) {
        cout << p.x << ' ' << p.y << ' ' << p.z << endl;
    }


    return 0;
}