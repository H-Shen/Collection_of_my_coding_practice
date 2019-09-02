// https://open.kattis.com/problems/busnumbers
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &&i : A) {
        scanf("%d", &i);
    }

    if (n == 1) {
        printf("%d\n", A.front());
    } else {
        sort(A.begin(), A.end());
        vector<string> output;
        int counter = 1;
        int lastOne = A.front();
        for (int i = 1; i < n; ++i) {
            if (A[i] - 1 == lastOne) {
                ++counter;
            } else {
                if (counter == 1) {
                    output.emplace_back(to_string(lastOne));
                } else if (counter == 2) {
                    output.emplace_back(to_string(lastOne - 1));
                    output.emplace_back(to_string(lastOne));
                } else {
                    output.emplace_back(to_string(lastOne - counter + 1) + "-" + to_string(lastOne));
                }
                counter = 1;
            }
            lastOne = A[i];
        }
        // handle the tail
        if (counter == 1) {
            output.emplace_back(to_string(lastOne));
        } else if (counter == 2) {
            output.emplace_back(to_string(lastOne - 1));
            output.emplace_back(to_string(lastOne));
        } else {
            output.emplace_back(to_string(lastOne - counter + 1) + "-" + to_string(lastOne));
        }
        // output
        bool firstItem = true;
        for (const string &i : output) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%s", i.c_str());
        }
        printf("\n");
    }

    return 0;
}
