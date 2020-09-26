#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 10;

enum class DIR : int {
    UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4
};

struct Node {
    explicit Node(int i, int j, DIR dir) : i(i), j(j), dir(dir) {}

    Node() = default;

    int i, j;
    DIR dir;

    bool operator==(const Node &other) const {
        return i == other.i && j == other.j && dir == other.dir;
    }

    [[nodiscard]] int get_hash() const {
        return i * MAXN + j + 10000 * (int) dir;
    }
};

struct custom_hash {
    size_t operator()(const pair<Node, Node> &obj) const {
        return hash<int>()(obj.first.get_hash()) ^
               hash<int>()(obj.second.get_hash());
    }
};

vector<vector<char> > M;
Node farmer, cow;
unordered_set<pair<Node, Node>, custom_hash> trace;

void rotate(Node &node) {
    switch (node.dir) {
        case DIR::UP:
            node.dir = DIR::RIGHT;
            break;
        case DIR::DOWN:
            node.dir = DIR::LEFT;
            break;
        case DIR::LEFT:
            node.dir = DIR::UP;
            break;
        case DIR::RIGHT:
            node.dir = DIR::DOWN;
            break;
    }
}

void advance(Node &node) {
    int new_i, new_j;
    int i = node.i;
    int j = node.j;
    switch (node.dir) {
        case DIR::UP:
            new_i = i - 1;
            new_j = j;
            if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN &&
                M.at(new_i).at(new_j) != '*') {
                node.i = new_i;
                node.j = new_j;
            } else {
                rotate(node);
            }
            break;
        case DIR::DOWN:
            new_i = i + 1;
            new_j = j;
            if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN &&
                M.at(new_i).at(new_j) != '*') {
                node.i = new_i;
                node.j = new_j;
            } else {
                rotate(node);
            }
            break;
        case DIR::LEFT:
            new_i = i;
            new_j = j - 1;
            if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN &&
                M.at(new_i).at(new_j) != '*') {
                node.i = new_i;
                node.j = new_j;
            } else {
                rotate(node);
            }
            break;
        case DIR::RIGHT:
            new_i = i;
            new_j = j + 1;
            if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN &&
                M.at(new_i).at(new_j) != '*') {
                node.i = new_i;
                node.j = new_j;
            } else {
                rotate(node);
            }
            break;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    for (int i = 0; i < MAXN; ++i) {
        cin >> s;
        M.emplace_back(s.begin(), s.end());
        for (int j = 0; j < MAXN; ++j) {
            if (s.at(j) == 'F') {
                farmer.i = i;
                farmer.j = j;
                farmer.dir = DIR::UP;
            } else if (s.at(j) == 'C') {
                cow.i = i;
                cow.j = j;
                cow.dir = DIR::UP;
            }
        }
    }
    int counter = 0;
    pair<Node, Node> temp;
    while (true) {
        if (farmer.i == cow.i && farmer.j == cow.j) {
            break;
        }
        temp.first = farmer;
        temp.second = cow;
        if (trace.find(temp) != trace.end()) {
            counter = 0;    // never encounter
            break;
        }
        trace.insert(temp);
        advance(farmer);
        advance(cow);
        ++counter;
    }
    cout << counter << '\n';

    return 0;
}
