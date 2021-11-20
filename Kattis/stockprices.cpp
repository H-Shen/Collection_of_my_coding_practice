// https://open.kattis.com/problems/stockprices

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    int price, share;
    Node() = default;
    Node(int price, int share) : price(price), share(share) {}
    bool operator < (const Node &node) const {
        return price < node.price;
    }
    bool operator > (const Node &node) const {
        return price > node.price;
    }
};

priority_queue<Node, vector<Node>, greater<> > sell;
priority_queue<Node, vector<Node>, less<> > buy;
int current_price;
int t, n;
string op, s;
int share, price;

void addSell(const Node& node) {
    if (sell.empty()) {
        sell.push(node);
        return;
    }
    if (node.price == sell.top().price) {
        auto head = sell.top();
        sell.pop();
        head.share += node.share;
        sell.push(head);
    }
    else {
        sell.push(node);
    }
}

void addBuy(const Node& node) {
    if (buy.empty()) {
        buy.push(node);
        return;
    }
    if (node.price == buy.top().price) {
        auto head = buy.top();
        buy.pop();
        head.share += node.share;
        buy.push(head);
    }
    else {
        buy.push(node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    Node node;
    while (t--) {
        current_price = -1;
        while (!sell.empty()) sell.pop();
        while (!buy.empty()) buy.pop();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> op >> share >> s >> s >> price;
            node.price = price;
            node.share = share;
            if (op == "buy") {
                addBuy(node);
            }
            else {
                addSell(node);
            }
            while (!sell.empty() && !buy.empty() && buy.top().price >= sell.top().price) {
                current_price = sell.top().price;
                if (buy.top().share > sell.top().share) {
                    auto head = buy.top();
                    head.share -= sell.top().share;
                    buy.pop();
                    buy.push(head);
                    sell.pop();
                }
                else if (buy.top().share == sell.top().share) {
                    buy.pop();
                    sell.pop();
                }
                else {
                    auto head = sell.top();
                    head.share -= buy.top().share;
                    sell.pop();
                    sell.push(head);
                    buy.pop();
                }
            }
            // output
            if (sell.empty()) {
                cout << '-';
            }
            else {
                cout << sell.top().price;
            }
            cout << ' ';
            if (buy.empty()) {
                cout << '-';
            }
            else {
                cout << buy.top().price;
            }
            cout << ' ';
            if (current_price == -1) {
                cout << '-' << '\n';
            }
            else {
                cout << current_price << '\n';
            }
        }
    }

    return 0;
}
