// https://open.kattis.com/problems/bestrelayteam
//

#include <bits/stdc++.h>

using namespace std;

struct Runner {
    string name;
    double a;
    double b;
};

int main() {

    int n;
    cin >> n;
    vector<Runner> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A.at(i).name >> A.at(i).a >> A.at(i).b;
    }
    sort(A.begin(), A.end(), [](const Runner &lhs, const Runner &rhs) {
        return (lhs.b < rhs.b);
    });
    double minTime = 100.0;
    double currentTime;
    vector<string> outputName(4);
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            currentTime = A.at(i).a + A.at(i + 1).b + A.at(i + 2).b + A.at(i + 3).b;
            if (currentTime < minTime) {
                minTime = currentTime;
                outputName.at(0) = A.at(i).name;
                outputName.at(1) = A.at(i + 1).name;
                outputName.at(2) = A.at(i + 2).name;
                outputName.at(3) = A.at(i + 3).name;
            }
        } else if (i == 1) {
            currentTime = A.at(i - 1).b + A.at(i).a + A.at(i + 1).b + A.at(i + 2).b;
            if (currentTime < minTime) {
                minTime = currentTime;
                outputName.at(0) = A.at(i).name;
                outputName.at(1) = A.at(i - 1).name;
                outputName.at(2) = A.at(i + 1).name;
                outputName.at(3) = A.at(i + 2).name;
            }
        } else if (i == 2) {
            currentTime = A.at(i - 2).b + A.at(i - 1).b + A.at(i).a + A.at(i + 1).b;
            if (currentTime < minTime) {
                minTime = currentTime;
                outputName.at(0) = A.at(i).name;
                outputName.at(1) = A.at(i - 2).name;
                outputName.at(2) = A.at(i - 1).name;
                outputName.at(3) = A.at(i + 1).name;
            }
        } else {
            currentTime = A.at(0).b + A.at(1).b + A.at(2).b + A.at(i).a;
            if (currentTime < minTime) {
                minTime = currentTime;
                outputName.at(0) = A.at(i).name;
                outputName.at(1) = A.at(0).name;
                outputName.at(2) = A.at(1).name;
                outputName.at(3) = A.at(2).name;
            }
        }
    }
    printf("%.9f\n", minTime);
    printf("%s\n", outputName.at(0).c_str());
    printf("%s\n", outputName.at(1).c_str());
    printf("%s\n", outputName.at(2).c_str());
    printf("%s\n", outputName.at(3).c_str());

    return 0;
}
