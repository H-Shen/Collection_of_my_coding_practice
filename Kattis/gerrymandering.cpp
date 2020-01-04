// https://open.kattis.com/problems/gerrymandering
//
#include<bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int p, d;
    cin >> p >> d;
    vector<pair<int, int> > A(d);
    int n, a, b;
    while (p--) {
        cin >> n >> a >> b;
        A.at(n - 1).first += a;
        A.at(n - 1).second += b;
    }
    int total, waste_votes_a, waste_votes_b, majority;
    int total_waste_votes_a = 0;
    int total_waste_votes_b = 0;
    int total_votes = 0;
    for (const auto &i : A) {
        total = i.first + i.second;
        total_votes += total;
        majority = total / 2 + 1;
        if (i.first > i.second) {
            cout << "A ";
            waste_votes_a = i.first - majority;
            waste_votes_b = i.second;
        } else {
            cout << "B ";
            waste_votes_a = i.first;
            waste_votes_b = i.second - majority;
        }
        total_waste_votes_a += waste_votes_a;
        total_waste_votes_b += waste_votes_b;
        cout << waste_votes_a << ' ' << waste_votes_b << endl;
    }
    printf("%.9lf\n", abs(total_waste_votes_a - total_waste_votes_b) * 1.0 / total_votes);

    return 0;
}
