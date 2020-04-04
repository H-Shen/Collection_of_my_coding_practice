#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

struct Node {
    ll x, y, z, r;
};

bool has_intersection(const Node &l, const Node &r) {
    return (l.x-r.x)*(l.x-r.x)+(l.y-r.y)*(l.y-r.y)+(l.z-r.z)*(l.z-r.z) <= (l.r+r.r)*(l.r+r.r);
}

bool intersect_with_upper_face(const Node &obj, ll h) {
    return (obj.z + obj.r) >= h;
}

bool intersect_with_lower_face(const Node &obj) {
    return (obj.z - obj.r) <= 0;
}

int main() {

    int T;
    int n;
    ll h, r;
    bool have_ans, touch_up, touch_down;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld %lld", &n, &h, &r);
        DSU::init(n);
        vector<Node> A(n);
        unordered_set<int> intersect_upper_faces;
        unordered_set<int> intersect_lower_faces;
        have_ans = false;
        for (auto &i : A) {
            scanf("%lld %lld %lld", &i.x, &i.y, &i.z);
            i.r = r;
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (has_intersection(A.at(i), A.at(j))) {
                    DSU::merge(i, j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (intersect_with_upper_face(A.at(i), h)) {
                intersect_upper_faces.insert(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (intersect_with_lower_face(A.at(i))) {
                intersect_lower_faces.insert(i);
            }
        }
        unordered_map<int, vector<int> > group2element;
        for (int i = 0; i < n; ++i) {
            group2element[DSU::find(i)].emplace_back(i);
        }
        for (const auto &[k, v_list] : group2element) {
            touch_down = false;
            touch_up = false;
            for (const auto v : v_list) {
                if (intersect_upper_faces.find(v) != intersect_upper_faces.end()) {
                    touch_up = true;
                }
                if (intersect_lower_faces.find(v) != intersect_lower_faces.end()) {
                    touch_down = true;
                }
            }
            if (touch_down && touch_up) {
                printf("Yes\n");
                have_ans = true;
                break;
            }
        }
        if (!have_ans) {
            printf("No\n");
        }
    }

    return 0;
}
