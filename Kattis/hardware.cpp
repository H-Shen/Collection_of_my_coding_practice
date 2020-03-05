// https://open.kattis.com/problems/hardware
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int c = getchar();
        t = 0;
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    }
    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    inline void write(T x) {
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template<typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

namespace DSU {
    vector<int> father;
    vector<int> Size;
    inline
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    inline
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    inline
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace Kruskal {
    struct Edge {
        int u, v, w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };
    bool cmp(const Edge &l, const Edge &r) {
        return l.w < r.w;
    }
    vector<Edge> init(vector<Edge> A, int number_of_nodes) {
        DSU::init(number_of_nodes);
        sort(A.begin(), A.end(), cmp);
        vector<Edge> result;
        for (const auto &i : A) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                result.emplace_back(i);
            }
        }
        return result;
    }
}

inline static
std::vector<std::string> splitByChar(std::string s, const char &delim) {
    std::vector<std::string> res;
    std::istringstream f(s);
    std::string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

bool is_digits(const string &s) {
    for (const char &ch : s) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

bool is_house_number(const vector<string> &p) {
    if (p.size() == 1 && is_digits(p.front())) {
        return true;
    }
    if (p.size() == 4 && p.front() == "+" && is_digits(p[1]) && is_digits(p[2]) && is_digits(p[3])) {
        return true;
    }
    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cin.get();
    string roadName;
    string nextRoadName;
    getline(cin, roadName);
    while (n--) {
        if (!nextRoadName.empty()) {
            roadName = nextRoadName;
        }
        int building;
        string building_str;
        cin >> building >> building_str;
        cin.get();
        building_str = to_string(building) + ' ' + building_str;
        string s;
        string total;
        while (true) {
            getline(cin, s);
            auto p = splitByChar(s, ' ');
            if (!is_house_number(p)) {
                nextRoadName = s;
                break;
            }
            // Case 1:
            if (p.size() == 1) {
                total += p.front();
            }
            // Case 2:
            else {
                int startNumber = stoi(p[1]);
                int endNumber = stoi(p[2]);
                int interval = stoi(p[3]);
                for (int i = startNumber; i <= endNumber; i += interval) {
                    total += to_string(i);
                }
            }
        }
        cout << roadName << '\n';
        cout << building_str << '\n';
        vector<int> stats(10);
        for (const char &ch : total) {
            ++stats.at(ch - '0');
        }
        for (int i = 0; i < 10; ++i) {
            cout << "Make " << stats.at(i) << " digit " << i << '\n';
        }
        if (total.size() == 1) {
            cout << "In total 1 digit" << '\n';
        } else {
            cout << "In total " << total.size() << " digits" << '\n';
        }
    }

    return 0;
}
