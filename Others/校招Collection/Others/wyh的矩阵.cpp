// https://ac.nowcoder.com/acm/problem/15426

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const size_t MAXN = 5005;

// A vector which supports a negative index.
template<typename T>
class myVector {
private:
    vector<T> A;
public:
    myVector(initializer_list<T> initializerList) : A(initializerList) {}
    vector<T> &getVector() {
        return A;
    }

    const T &get(int i) const {
        int length = static_cast<int>(A.size());
        if (i >= length || i < -length) {
            throw out_of_range("");
        }
        if (i < 0) {
            return A.at(length + i);
        }
        return A.at(i);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    myVector<ll> obj({1,25,169,625,1681});
    while (obj.getVector().size() < MAXN) {
        obj.getVector().emplace_back(5*obj.get(-1) - 10*obj.get(-2)+10*obj.get(-3)-5*obj.get(-4)+obj.get(-5));
    }
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << obj.get((n - 1) / 2) << endl;
    }
    return 0;
}