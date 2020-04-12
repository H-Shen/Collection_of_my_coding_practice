#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 105;
char cstr[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    vector<pair<string, int> > A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        A.at(i).first = cstr;
        A.at(i).second = i + 1;
    }
    auto result = *max_element(A.begin(), A.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs){
        if (lhs.first.size() == rhs.first.size()) {
            if (lhs.first == rhs.first) {
                return lhs.second > rhs.second;
            }
            return lhs.first < rhs.first;
        }
        return (lhs.first.size() < rhs.first.size());
    });
    printf("%d\n%s\n", result.second, result.first.c_str());

    return 0;
}
