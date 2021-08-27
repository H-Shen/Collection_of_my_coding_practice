class Solution {
public:
    bool check(vector<int> l, vector<int> r, int i) {
        l.erase(l.begin()+i);
        l.emplace_back(r.back());
        return l == r;
    }
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int n = (int)sensor1.size();
        bool b1, b2;
        for (int i = 0; i < n; ++i) {
            if (sensor1[i] != sensor2[i]) {
                b1 = check(sensor1, sensor2, i);
                b2 = check(sensor2, sensor1, i);
                if (b1 && !b2) {
                    return 2;
                }
                else if (!b1 && b2) {
                    return 1;
                }
                break;
            }
        }
        return -1;
    }
};