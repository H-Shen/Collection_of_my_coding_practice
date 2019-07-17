#include <vector>
#include <iostream>

using namespace std;

vector <vector<int> > arr;

int main() {

    ios_base::sync_with_stdio(false);
    int n, query, len, query_i, query_j, temp;
    cin >> n >> query;
    for (int i = 0; i < n; ++i) {
        cin >> len;
        vector<int> subArr;
        for (int j = 0; j < len; ++j) {
            cin >> temp;
            subArr.emplace_back(temp);
        }
        arr.emplace_back(subArr);
    }

    for (int i = 0; i < query; ++i) {
        cin >> query_i >> query_j;
        cout << arr[query_i][query_j] << endl;
    }

    return 0;
}
