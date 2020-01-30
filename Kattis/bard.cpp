#include <bits/extc++.h>

using namespace std;

int songNumber = 0;

inline static
vector<int> merge(const vector<vector<int> > &A) {
    if (A.size() == 1) {
        return A.front();
    }
    vector<int> res = A.front();
    vector<int> temp;
    for (size_t i = 1; i != A.size(); ++i) {
        vector<int>().swap(temp);
        set_union(res.begin(), res.end(), A.at(i).begin(), A.at(i).end(), back_inserter(temp));
        res = temp;
    }
    return res;
}

int main() {

    int n;
    scanf("%d", &n);
    vector<vector<int> > Counter(n + 5);

    int e;
    int k;
    scanf("%d", &e);    // e nights
    bool hasBard;
    for (int i = 0; i < e; ++i) {
        hasBard = false;
        scanf("%d", &k);
        vector<int> A(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &A.at(j));
            if (A.at(j) == 1) {
                hasBard = true;
            }
        }
        if (hasBard) {
            for (const auto &item : A) {
                Counter[item].emplace_back(songNumber);
            }
            ++songNumber;
        } else {
            // exchange all songs
            vector<vector<int> > temp;
            for (const auto &item : A) {
                temp.emplace_back(Counter.at(item));
            }
            vector<int> temp_vec = merge(temp);
            // update
            for (const auto &item : A) {
                Counter.at(item) = temp_vec;
            }
        }
    }
    // output
    vector<int> output;
    for (int i = 1; i <= n; ++i) {
        if (Counter[i].size() == Counter[1].size()) {
            output.emplace_back(i);
        }
    }
    for (const auto &i : output) {
        printf("%d\n", i);
    }

    return 0;
}