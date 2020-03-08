// https://open.kattis.com/problems/shortestpath1
//
#include <bits/extc++.h>

using namespace std;

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

namespace SSSP {
    constexpr int MAX_NODES = 10005;
    constexpr int MAX_EDGES = 30005;
    constexpr int INF = 0x3f3f3f3f;
    struct Edge {
        int to;
        int distance;
        int next;
        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };
    vector<Edge> E(MAX_EDGES);
    vector<int> head(MAX_NODES);
    int counter;
    vector<int> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    int s;
    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }
    struct Node {
        int distance;
        int position;

        explicit Node(int distance, int pos) : distance(distance), position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };
    priority_queue<Node> Q;
    inline void dijkstra() {
        dis.at(s) = 0;
        Q.push(Node(0, s));
        while (!Q.empty()) {
            Node tmp = Q.top();
            Q.pop();
            int x = tmp.position;
            // Base case
            if (vis.at(x)) {
                continue;
            }
            vis.at(x) = true;
            for (int i = head.at(x); i; i = E.at(i).next) {
                int y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (!vis.at(y)) {
                        Q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
    inline void reset() {
        fill(dis.begin(), dis.end(), INF);
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        Q = std::priority_queue<Node>();
    }
}


int main() {

    int n, m, q, s, u, v, w, dest;
    bool first_case = true;
    while (true) {
        if (first_case) {
            first_case = false;
        } else {
            FastIO::putcharWithFwrite('\n');
        }
        FastIO::readIntUsingFread(n);
        FastIO::readIntUsingFread(m);
        FastIO::readIntUsingFread(q);
        FastIO::readIntUsingFread(s);
        if (n == 0 && m == 0 && q == 0 && s == 0) {
            break;
        }
        while (m--) {
            FastIO::readIntUsingFread(u);
            FastIO::readIntUsingFread(v);
            FastIO::readIntUsingFread(w);
            ++u;
            ++v;
            SSSP::add_edge(u, v, w);
        }
        while (q--) {
            // reset all distances
            SSSP::reset();
            SSSP::s = s + 1;
            FastIO::readIntUsingFread(dest);
            ++dest;
            SSSP::dijkstra();
            if (SSSP::dis.at(dest) == SSSP::INF) {
                FastIO::putcharWithFwrite('I');
                FastIO::putcharWithFwrite('m');
                FastIO::putcharWithFwrite('p');
                FastIO::putcharWithFwrite('o');
                FastIO::putcharWithFwrite('s');
                FastIO::putcharWithFwrite('s');
                FastIO::putcharWithFwrite('i');
                FastIO::putcharWithFwrite('b');
                FastIO::putcharWithFwrite('l');
                FastIO::putcharWithFwrite('e');
                FastIO::putcharWithFwrite('\n');
            } else {
                FastIO::writeIntWithFwrite(SSSP::dis.at(dest));
                FastIO::putcharWithFwrite('\n');
            }
        }
        // reset all edges
        vector<SSSP::Edge>().swap(SSSP::E);
        SSSP::E.resize(SSSP::MAX_EDGES);
        fill(SSSP::head.begin(), SSSP::head.end(), 0);
        SSSP::counter = 0;
    }
    FastIO::flushAfterWriteIntWithFwrite();

    return 0;
}
