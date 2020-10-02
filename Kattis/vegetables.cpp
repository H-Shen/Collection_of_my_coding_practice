// https://open.kattis.com/problems/vegetables
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;

auto sgn = [](const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
};

auto weight_to_cut = [](const auto &obj) {
    return obj.weight * 1.0 / ((double) obj.cut + 1);
};

auto get_ratio = [](const auto &l, const auto &r) {
    return weight_to_cut(l) / weight_to_cut(r);
};

struct Node {
    explicit Node(ll weight, ll cut, int id) : weight(weight), cut(cut),
                                               id(id) {}

    ll weight;
    ll cut;
    int id;
};

struct myCmp {
    bool operator()(const Node &l, const Node &r) const {
        double l_ = weight_to_cut(l);
        double r_ = weight_to_cut(r);
        if (abs(l_ - r_) < EPS) {
            if (l.weight == r.weight) {
                return (l.id < r.id);
            }
            return (l.weight > r.weight);
        }
        return (sgn(l_ - r_) < 0);
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    double t;
    int n;
    cin >> t >> n;
    set<Node, myCmp> A;
    ll weight;
    for (int id = 0; id < n; ++id) {
        cin >> weight;
        A.insert(Node(weight, 0, id));
    }
    ll counter = 0;
    while (true) {
        if (sgn(get_ratio(*A.begin(), *A.rbegin()) - t) >= 0) {
            break;
        }
        auto iter_to_last = A.rbegin();
        Node last_node =*iter_to_last;
        A.erase(last_node);
        ++last_node.cut;
        ++counter;
        A.insert(last_node);
    }
    cout << counter << '\n';
    return 0;
}
