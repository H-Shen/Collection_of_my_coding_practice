// https://www.nowcoder.com/practice/738a3511d8d14f189481a62e725e2775
#include <bits/stdc++.h>

using namespace std;

int main() {

    char ch;
    string s;
    vector<int> A;
    while (~scanf("%c", &ch)) {
        if (ch == ',') {
            A.emplace_back(stoi(s));
            s = "";
        } else {
            s.push_back(ch);
        }
    }
    A.emplace_back(stoi(s));
    pair<int, int> a = make_pair(A[0], A[1]);
    vector<pair<int, int> > L(A[2]);
    for (int i = 0; i < A[2]; ++i) {
        L[i] = make_pair(A[2 * i + 3], A[2 * i + 4]);

    }
    
    int min_dist = 0x3f3f3f3f;
    for (int i = 0; i < A[2]; ++i) {
        min_dist = min(min_dist, (L[i].first - a.first)*(L[i].first - a.first)+(L[i].second - a.second)*(L[i].second - a.second));
    }

    for (int i = 0; i < A[2]; ++i) {
        if ((L[i].first - a.first)*(L[i].first - a.first)+(L[i].second - a.second)*(L[i].second - a.second) == min_dist) {
            printf("(%d,%d)\n", L[i].first, L[i].second);
            break;
        }
    }

    return 0;
}