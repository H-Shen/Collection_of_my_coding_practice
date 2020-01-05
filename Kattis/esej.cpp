// https://open.kattis.com/problems/esej
//
#include<bits/stdc++.h>

using namespace std;

int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    vector<string> A(b);
    int idx = 0;

    for (char i = 'a'; i <= 'z'; ++i) {
        for (char j = 'a'; j <= 'z'; ++j) {
            for (char k = 'a'; k <= 'z'; ++k) {
                for (char m = 'a'; m <= 'z'; ++m) {
                    if (idx == b) {
                        goto label1;
                    }
                    A.at(idx) = "aaaa";
                    A.at(idx).at(0) = i;
                    A.at(idx).at(1) = j;
                    A.at(idx).at(2) = k;
                    A.at(idx).at(3) = m;
                    ++idx;
                }
            }
        }
    }

label1:
    {
        bool firstItem = true;
        for (int i = 0; i < b; ++i) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%s", A.at(i).c_str());
        }
        printf("\n");
    }
    return 0;
}
