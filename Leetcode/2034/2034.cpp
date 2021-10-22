class StockPrice {
private:
    unordered_map<int,int> records;
    multiset<int> prices;
    int currentTimestamp;
public:
    StockPrice() {
        currentTimestamp = 0;
    }
    void update(int timestamp, int price) {
        if (records.find(timestamp) != records.end()) {
            int oldPrice = records[timestamp];
            auto iter = prices.find(oldPrice);
            prices.erase(iter);
        }
        records[timestamp] = price;
        prices.insert(price);
        currentTimestamp = max(currentTimestamp, timestamp);
    }
    
    int current() {
        return records[currentTimestamp];
    }
    
    int maximum() {
        return *(--prices.end());
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */