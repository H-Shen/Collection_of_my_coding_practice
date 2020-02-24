#pragma GCC optimize("Ofast")
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;


namespace FastIO {

    static constexpr int MAXSIZE = 1024 * 1024;
    static char inputBuffer[MAXSIZE];
    static char *ptr1 = inputBuffer + MAXSIZE;
    static char *ptr2 = inputBuffer + MAXSIZE;
    static char outputBuffer[MAXSIZE];
    static char *ptr = outputBuffer;

    inline static
    char getcharUsingFread() {
        if (ptr1 == ptr2) {
            ptr1 = inputBuffer;
            ptr2 = inputBuffer + fread(inputBuffer, 1, MAXSIZE, stdin);
            if (ptr1 == ptr2) {
                return EOF;
            }
        }
        return *ptr1++;
    }

    inline static
    void putcharWithFwrite(const char &ch) {
        if (ptr - outputBuffer == MAXSIZE) {
            fwrite(outputBuffer, 1, MAXSIZE, stdout);
            ptr = outputBuffer;
        }
        *ptr++ = ch;
    }

    template<class T>
    inline static
    void writeIntWithFwrite(T x) {
        if (x < 0) {
            x = -x;
            putcharWithFwrite('-');
        }
        static int storeDigits[40];
        int top = 0;
        do {
            storeDigits[top++] = x % 10;
            x /= 10;
        } while (x);
        while (top) {
            putcharWithFwrite(static_cast<T>(storeDigits[--top]) + 48);
        }
    }

    void flushAfterWriteIntWithFwrite() {
        fwrite(outputBuffer, 1, ptr - outputBuffer, stdout);
    }

    template<typename T>
    inline static
    void readIntUsingFread(T &x) {
        x = 0;
        bool isNeg = false;
        char ch = getcharUsingFread();

        // skip all non digit characters
        while (!isdigit(ch)) {
            if (ch == '-') {
                isNeg = true;
            }
            ch = getcharUsingFread();
        }

        while (isdigit(ch)) {
            x = x * 10 + static_cast<T>(ch ^ 48);
            ch = getcharUsingFread();
        }
        x = isNeg ? -x : x;
    }
}

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
        if (father[x] != x) {
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
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

// The collection of methods and data structures for Kruskal's algorithm
namespace Kruskal {
    struct Edge {
        int u, v;
        ll w;
        Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &lhs, const Edge &rhs) {
        return (lhs.w < rhs.w);
    }
    struct my_hash_func {
        size_t operator ()(const pair<int, int> &obj) const {
            return hash<int>()(obj.first) ^ hash<int>()(obj.second);
        }
    };
    ll init(const vector<Edge> &E, int number_of_nodes) {
        // init a DSU
        DSU::init(number_of_nodes);
        // We use a hashmap to store the minimal weight between a pair of nodes
        unordered_map<pair<int, int>, ll, my_hash_func> temp_unmap;
        pair<int, int> temp_pair;
        for (const auto &[u, v, w] : E) {
            if (u > v) {
                temp_pair.first = v;
                temp_pair.second = u;
            } else {
                temp_pair.first = u;
                temp_pair.second = v;
            }
            if (temp_unmap.find(temp_pair) == temp_unmap.end()) {
                temp_unmap[temp_pair] = w;
            } else {
                temp_unmap[temp_pair] = min(w, temp_unmap[temp_pair]);
            }
        }
        vector<Edge> E_filter(temp_unmap.size());
        int index = 0;
        for (const auto &[nodes, w] : temp_unmap) {
            E_filter.at(index).u = nodes.first;
            E_filter.at(index).v = nodes.second;
            E_filter.at(index).w = w;
            ++index;
        }
        sort(E_filter.begin(), E_filter.end(), cmp);
        ll max_cost = -1;
        for (const auto &[u, v, w] : E_filter) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                max_cost = max(max_cost, w);
            }
        }
        return max_cost;
    }
}


int main() {

    int n, m;
    FastIO::readIntUsingFread(n);
    FastIO::readIntUsingFread(m);
    vector<Kruskal::Edge> A(m);
    int random_city = 0;
    for (int i = 0; i < m; ++i) {
        FastIO::readIntUsingFread(A.at(i).u);
        FastIO::readIntUsingFread(A.at(i).v);
        FastIO::readIntUsingFread(A.at(i).w);
        random_city = A.at(i).u;
    }
    auto result = Kruskal::init(A, n);
    if (DSU::Size[DSU::find(random_city)] != n) {
        FastIO::putcharWithFwrite('I');
        FastIO::putcharWithFwrite('M');
        FastIO::putcharWithFwrite('P');
        FastIO::putcharWithFwrite('O');
        FastIO::putcharWithFwrite('S');
        FastIO::putcharWithFwrite('S');
        FastIO::putcharWithFwrite('I');
        FastIO::putcharWithFwrite('B');
        FastIO::putcharWithFwrite('L');
        FastIO::putcharWithFwrite('E');
    } else {
        FastIO::writeIntWithFwrite(result);
    }
    FastIO::putcharWithFwrite('\n');
    FastIO::flushAfterWriteIntWithFwrite();
    return 0;
}
