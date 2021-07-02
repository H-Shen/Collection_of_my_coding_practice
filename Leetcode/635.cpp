struct Timestamp {
    int year, month, day, hour, minute, second;
    Timestamp() = default;
    Timestamp(const string &s) {
        sscanf(s.c_str(),"%d:%d:%d:%d:%d:%d",&year,&month,&day,&hour,&minute,&second);
    }
    bool operator < (const Timestamp &o) const {
        if (year == o.year) {
            if (month == o.month) {
                if (day == o.day) {
                    if (hour == o.hour) {
                        if (minute == o.minute) {
                            return second < o.second;
                        }
                        return minute < o.minute;
                    }
                    return hour < o.hour;
                }
                return day < o.day;
            }
            return month < o.month;
        }
        return year < o.year;
    }
    bool operator == (const Timestamp &o) const {
        return year == o.year && month == o.month && day == o.day && hour == o.hour && minute == o.minute && second == o.second;
    }
    friend ostream &operator<<(ostream &os, const Timestamp &timestamp) {
        os << "year: " << timestamp.year << " month: " << timestamp.month << " day: " << timestamp.day << " hour: "
           << timestamp.hour << " minute: " << timestamp.minute << " second: " << timestamp.second;
        return os;
    }
};

Timestamp solve(const Timestamp &t, const string &gran) {
    Timestamp ans;
    ans.year = 1; ans.month = 1; ans.day = 1; ans.hour = 0; ans.minute = 0; ans.second = 0;
    if (gran == "Year") {
        ans.year = t.year;
    }
    else if (gran == "Month") {
        ans.year = t.year;
        ans.month = t.month;
    }
    else if (gran == "Day") {
        ans.year = t.year;
        ans.month = t.month;
        ans.day = t.day;
    }
    else if (gran == "Hour") {
        ans.year = t.year;
        ans.month = t.month;
        ans.day = t.day;
        ans.hour = t.hour;
    }
    else if (gran == "Minute") {
        ans.year = t.year;
        ans.month = t.month;
        ans.day = t.day;
        ans.hour = t.hour;
        ans.minute = t.minute;
    }
    else {
        ans.year = t.year;
        ans.month = t.month;
        ans.day = t.day;
        ans.hour = t.hour;
        ans.minute = t.minute;
        ans.second = t.second;
    }
    return ans;
}

class LogSystem {
private:
    map<Timestamp, vector<int> > m;  
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        m[Timestamp(timestamp)].emplace_back(id);
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> ans;
        if (m.empty()) return ans;
        Timestamp s = solve(start, granularity);
        Timestamp e = solve(end, granularity);
        auto iter = m.lower_bound(s);
        if (iter == m.end()) return ans;
        while (true) {
            if (iter == m.end()) break;
            Timestamp temp = solve(iter->first, granularity);
            if (temp < e || temp == e) {
                for (const auto &i : iter->second) {
                    ans.emplace_back(i);
                }
                ++iter;
            }
            else break;
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */