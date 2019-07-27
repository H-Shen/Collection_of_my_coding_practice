#include <vector>
#include <iostream>

using namespace std;
const size_t MAX_ELEMENT = 30;
vector<int> A;
int cnt, n;

void dfs(int Rest, int End, int Num) {
    if (!Rest) {
        ++cnt;
        if (cnt % 4 != 1) {
            cout << ";";
        }
        cout << n << "=" << A.at(0);
        for (int i = 1; i < Num; ++i) {
            cout << "+" << A.at(static_cast<size_t>(i));
        }
        if (cnt % 4 == 0) {
            cout << endl;
        }
    } else {
        for (int i = End; i <= Rest; ++i) {
            A.at(static_cast<size_t>(Num)) = i;
            dfs(Rest - i, i, Num + 1);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    A.resize(MAX_ELEMENT);
    cin >> n;
    if (n <= 0 || n > 30) {
        return 0;
    }
    dfs(n, 1, 0);
    if (cnt % 4 != 0) {
        cout << endl;
    }

    return 0;
}