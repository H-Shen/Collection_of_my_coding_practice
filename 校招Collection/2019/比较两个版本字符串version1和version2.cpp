// https://www.nowcoder.com/practice/521049ca23f147d698e1cff923c3262a

#include <bits/stdc++.h>

using namespace std;

inline
int threeWayCompare(const vector<int> &A, const vector<int> &B) {
    size_t minLen = min(A.size(), B.size());
    for (size_t i = 0; i != minLen; ++i) {
        if (A.at(i) > B.at(i)) {
            return 1;
        } else if (A.at(i) < B.at(i)) {
            return -1;
        }
    }
    if (A.size() > B.size()) {
        return 1;
    } else if (A.size() < B.size()) {
        return -1;
    }
    return 0;
}

inline
vector<int> getVersion(const string &s) {
    vector<int> result;
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, '.')) {
        result.emplace_back(stoi(temp));
    }
    return result;
}

int main() {

    string a;
    cin >> a;
    vector<int> A = getVersion(a);
    string b;
    cin >> b;
    vector<int> B = getVersion(b);

    cout << threeWayCompare(A, B) << endl;

    return 0;
}