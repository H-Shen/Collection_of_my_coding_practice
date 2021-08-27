class UndergroundSystem {
private:
    unordered_map<int, pair<string, int> > checkInUmap;
    unordered_map<string, unordered_map<string, vector<int> > > unmap;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        if (checkInUmap.find(id) == checkInUmap.end()) {
            checkInUmap[id] = make_pair(stationName, t);
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if (checkInUmap.find(id) == checkInUmap.end()) return;
        string endStation = stationName;
        string startStation = checkInUmap[id].first;
        int dist_t = t - checkInUmap[id].second;
        unmap[startStation][endStation].emplace_back(dist_t);
        checkInUmap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto &ref = unmap[startStation][endStation];
        if (ref.empty()) return 0.0;
        return accumulate(ref.begin(), ref.end(), int(0)) * 1.0 / (int)ref.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */