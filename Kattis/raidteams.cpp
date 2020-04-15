// https://open.kattis.com/problems/raidteams
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 15;
constexpr int MINIMAL_PLAYERS = 3;
char cstr[MAXN];

template<typename T>
using RBTree = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct NodeA {
    string name;
    int a;

    explicit NodeA(string name, int a) : name(std::move(name)), a(a) {}

    bool operator>(const NodeA &other) const {
        if (a == other.a) {
            return (name < other.name);
        }
        return (a > other.a);
    }
};

struct NodeB {
    string name;
    int b;

    explicit NodeB(string name, int b) : name(std::move(name)), b(b) {}

    bool operator>(const NodeB &other) const {
        if (b == other.b) {
            return (name < other.name);
        }
        return (b > other.b);
    }
};

struct NodeC {
    string name;
    int c;

    explicit NodeC(string name, int c) : name(std::move(name)), c(c) {}

    bool operator>(const NodeC &other) const {
        if (c == other.c) {
            return (name < other.name);
        }
        return (c > other.c);
    }
};

RBTree<NodeA> TreeA;
RBTree<NodeB> TreeB;
RBTree<NodeC> TreeC;
unordered_map<string, tuple<int, int, int> > store;

int main() {

    int n, a, b, c;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", cstr, &a, &b, &c);
        s = cstr;
        get<0>(store[s]) = a;
        get<1>(store[s]) = b;
        get<2>(store[s]) = c;
        TreeA.insert(NodeA(s, a));
        TreeB.insert(NodeB(s, b));
        TreeC.insert(NodeC(s, c));
    }
    if (store.size() < MINIMAL_PLAYERS) {
        return 0;
    }
    array<string, MINIMAL_PLAYERS> team_names;
    while (store.size() >= MINIMAL_PLAYERS) {
        // get the first player
        auto first_player = TreeA.find_by_order(0);
        // store it in the list
        team_names.at(0) = first_player->name;
        // delete the first player from TreeA
        TreeA.erase(first_player);
        // delete the first player from TreeB
        TreeB.erase(NodeB(team_names.at(0), get<1>(store[team_names.at(0)])));
        // delete the first player from TreeC
        TreeC.erase(NodeC(team_names.at(0), get<2>(store[team_names.at(0)])));
        // delete the first player from the hash map
        store.erase(team_names.at(0));

        // get the second player
        auto second_player = TreeB.find_by_order(0);
        // store it in the list
        team_names.at(1) = second_player->name;
        // delete the second player from TreeA
        TreeA.erase(NodeA(team_names.at(1), get<0>(store[team_names.at(1)])));
        // delete the second player from TreeB
        TreeB.erase(second_player);
        // delete the second player from TreeC
        TreeC.erase(NodeC(team_names.at(1), get<2>(store[team_names.at(1)])));
        // delete the second player from the hash map
        store.erase(team_names.at(1));

        // get the third player
        auto third_player = TreeC.find_by_order(0);
        // store it in the list
        team_names.at(2) = third_player->name;
        // delete the third player from TreeA
        TreeA.erase(NodeA(team_names.at(2), get<0>(store[team_names.at(2)])));
        // delete the third player from TreeB
        TreeB.erase(NodeB(team_names.at(2), get<1>(store[team_names.at(2)])));
        // delete the third player from TreeC
        TreeC.erase(third_player);
        // delete the third player from the hash map
        store.erase(team_names.at(2));

        // output
        sort(team_names.begin(), team_names.end());
        printf("%s %s %s\n", team_names.at(0).c_str(), team_names.at(1).c_str(),
               team_names.at(2).c_str());
    }

    return 0;
}
