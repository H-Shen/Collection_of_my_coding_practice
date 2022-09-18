const int A[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int m, d;
    Date(int m, int d) : m(m), d(d) {}
    Date() = default;
    Date(const string& s) {
        m = stoi(s.substr(0, 2));
        d = stoi(s.substr(3));
    }
    bool operator == (const Date& other) const {
        return m == other.m && d == other.d;
    }
    void increase() {
        if (d == A[m-1]) {
            if (m == 12) {
                d = 1;
                m = 1;
            }
            else {
                d = 1;
                ++m;
            }
        }
        else {
            ++d;
        }
    }
};

struct MyHashFunc {
    size_t operator () (const Date& date) const {
        return hash<int>()(date.m) ^ hash<int>()(date.d);
    }  
};

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        Date a(arriveAlice);
        Date b(leaveAlice);
        int counter = 0;
        unordered_set<Date, MyHashFunc> unset;
        while (true) {
            unset.insert(a);
            if (a == b) {
                break;
            }
            a.increase();
        }
        Date c(arriveBob);
        Date d(leaveBob);
        while (true) {
            if (unset.count(c) > 0) {
                ++counter;
            }
            if (c == d) {
                break;
            }
            c.increase();
        }
        return counter;
    }
};