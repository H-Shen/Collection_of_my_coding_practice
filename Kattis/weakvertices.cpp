// https://open.kattis.com/problems/weakvertices
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int n;
    int val;
    pair<int, int> p;
    string s;
    string edge1;
    string edge2;
    string edge3;
    bool firstItem;

    while (true) {

        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        unordered_map<string, pair<int, int> > A;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &val);
                if (val == 1) {
                    p.first = i;
                    p.second = j;
                    if (p.first > p.second) {
                        swap(p.first, p.second);
                    }
                    s = to_string(p.first) + " " + to_string(p.second);
                    A[s] = p;
                }
            }
        }
        unordered_set<int> pointsThatCanFormTriangles;

        // i < j < k
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    edge1 = to_string(i) + " " + to_string(j);
                    edge2 = to_string(j) + " " + to_string(k);
                    edge3 = to_string(i) + " " + to_string(k);
                    if (A.find(edge1) != A.end() && A.find(edge2) != A.end() &&
                        A.find(edge3) != A.end()) {
                        pointsThatCanFormTriangles.insert(i);
                        pointsThatCanFormTriangles.insert(j);
                        pointsThatCanFormTriangles.insert(k);
                    }
                }
            }
        }

        vector<int> output;
        for (int i = 0; i < n; ++i) {
            if (pointsThatCanFormTriangles.find(i) ==
                pointsThatCanFormTriangles.end()) {
                output.emplace_back(i);
            }
        }
        sort(output.begin(), output.end());
        firstItem = true;
        for (const auto &i : output) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}
