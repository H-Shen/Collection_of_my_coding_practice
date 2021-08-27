class SeatManager {
public:
    set<int> emptySeats;
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            emptySeats.insert(i);
        }
    }
    
    int reserve() {
        auto iter = emptySeats.begin();
        int ans = *iter;
        emptySeats.erase(iter);
        return ans;
    }
    
    void unreserve(int seatNumber) {
        emptySeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */