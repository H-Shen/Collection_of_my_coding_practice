#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 10;
char cstr[MAXN];

struct Student {
    string name;
    int chinese;
    int math;
    int english;
    int total;
};

int main() {
    int n;
    scanf("%d", &n);
    vector<Student> A(n);
    for (auto &i : A) {
        scanf("%s %d %d %d", cstr, &i.chinese, &i.math, &i.english);
        i.name = cstr;
        i.total = i.chinese + i.math + i.english;
    }
    vector<pair<string, string> > output;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (abs(A.at(i).chinese - A.at(j).chinese) <= 5 &&
                    abs(A.at(i).math - A.at(j).math) <= 5 &&
                    abs(A.at(i).english - A.at(j).english) <= 5 &&
                    abs(A.at(i).total - A.at(j).total) <= 10) {
                output.emplace_back(A.at(i).name, A.at(j).name);
            }
        }
    }
    for (auto &i : output) {
        if (i.first > i.second) {
            swap(i.first, i.second);
        }
    }
    sort(output.begin(), output.end(), [](const pair<string, string> &lhs, const pair<string, string> &rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first < rhs.first;
    });
    for (const auto &i : output) {
        printf("%s %s\n", i.first.c_str(), i.second.c_str());
    }
    return 0;
}