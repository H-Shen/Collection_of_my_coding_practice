using ll = long long;
constexpr ll MOD = 1e9+7;

struct Sell {
    int amount, price;
    Sell(int amount, int price) : amount(amount), price(price) {}
    bool operator < (const Sell &sell) const {
        return price > sell.price;
    }
};

struct Buy {
    int amount, price;
    Buy(int amount, int price) : amount(amount), price(price) {}
    bool operator < (const Buy &buy) const {
        return price < buy.price;
    }
};

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<Sell, vector<Sell>, less<> > sellOrder;
        priority_queue<Buy, vector<Buy>, less<> > buyOrder;
        for (auto &i : orders) {
            // buy
            if (i[2] == 0) {
                if (sellOrder.empty()) {
                    buyOrder.push(Buy(i[1],i[0]));
                    continue;
                }
                if (sellOrder.top().price <= i[0]) {
                    while (!sellOrder.empty() && sellOrder.top().price <= i[0]) {
                        if (sellOrder.top().amount > i[1]) {
                            auto temp = sellOrder.top();
                            sellOrder.pop();
                            temp.amount -= i[1];
                            sellOrder.push(temp);
                            i[1] = 0;
                            break;
                        }
                        else {
                            i[1] -= sellOrder.top().amount;
                            sellOrder.pop();
                        }
                    }
                    if (i[1] > 0) {
                        buyOrder.push(Buy(i[1],i[0]));
                    }
                }
                else {
                    buyOrder.push(Buy(i[1],i[0]));
                }
            }
            // sell
            else {
                if (buyOrder.empty()) {
                    sellOrder.push(Sell(i[1],i[0]));
                    continue;
                }
                if (buyOrder.top().price >= i[0]) {
                    while (!buyOrder.empty() && buyOrder.top().price >= i[0]) {
                        if (buyOrder.top().amount > i[1]) {
                            auto temp = buyOrder.top();
                            buyOrder.pop();
                            temp.amount -= i[1];
                            buyOrder.push(temp);
                            i[1] = 0;
                            break;
                        }
                        else {
                            i[1] -= buyOrder.top().amount;
                            buyOrder.pop();
                        }
                    }
                    if (i[1] > 0) {
                        sellOrder.push(Sell(i[1],i[0]));
                    }
                }
                else {
                    sellOrder.push(Sell(i[1],i[0]));
                }
            }
        }
        ll ans = 0;
        while (!sellOrder.empty()) {
            ans += (ll)sellOrder.top().amount;
            sellOrder.pop();
        }
        while (!buyOrder.empty()) {
            ans += (ll)buyOrder.top().amount;
            buyOrder.pop();
        }
        return (int)(ans % MOD);
    }
};