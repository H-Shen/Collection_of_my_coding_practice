// https://open.kattis.com/problems/janeeyre
// 
#include <bits/extc++.h>

#include <utility>

using namespace std;
using ll = long long;

struct Node {
    string name;
    ll pages;
    Node() = default;
    Node(string name, ll pages) : name(std::move(name)), pages(pages) {}
    bool operator < (const Node &other) const {
        return name > other.name;
    }
};

Node parse(const string &s) {
    string name;
    string pages;
    int n = (int)s.size();
    int i;
    int counter = 0;
    for (i = 0; i < n; ++i) {
        if (s[i] == '\"') {
            ++counter;
            if (counter > 1) {
                break;
            }
        } else if (counter == 1) {
            name.push_back(s[i]);
        }
    }
    for (; i < n; ++i) {
        if (isdigit(s[i])) {
            pages.push_back(s[i]);
        }
    }
    return Node(name, stoll(pages));
}

pair<int, Node> parse2(const string &s) {
    string time;
    int i = 0;
    while (isdigit(s[i])) {
        time += s[i];
        ++i;
    }
    return {stoll(time), parse(s.substr(i))};
}

priority_queue<Node, vector<Node>, less<> > pq;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    cin.get();
    string s;
    pq.push(Node("Jane Eyre", k));
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        pq.push(parse(s));
    }
    deque<pair<ll, Node> > receives;
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        receives.emplace_back(parse2(s));
    }
    ll currentTime = 0;
    sort(receives.begin(), receives.end(), [](const pair<ll, Node> &l, const pair<ll, Node>&r){
        return l.first < r.first;
    });
    while (!pq.empty()) {
        currentTime += pq.top().pages;
        if (pq.top().name == "Jane Eyre") {
            cout << currentTime << '\n';
            return 0;
        }
        pq.pop();
        while (!receives.empty() && receives.front().first <= currentTime) {
            pq.push(receives.front().second);
            receives.pop_front();
        }
    }

    return 0;
}
