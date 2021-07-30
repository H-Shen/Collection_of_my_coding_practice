constexpr int MAXN = 205;

class Cashier {
private:
    int n, discount, counter;
    int id2price[MAXN];
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) : n(n), discount(discount), counter(0) {
        memset(id2price, 0, sizeof id2price);
        int length = (int)products.size();
        for (int i = 0; i < length; ++i) {
            id2price[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double ans = 0.0;
        int length = (int)product.size();
        for (int i = 0; i < length; ++i) {
            ans += id2price[product[i]] * amount[i];
        }
        ++counter;
        if (counter == n) {
            ans *= (1.0 - discount / 100.0);
            counter = 0;
        }
        return ans;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */