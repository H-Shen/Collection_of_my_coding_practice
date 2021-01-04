class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &l, const vector<int> &r){
            return l[1] > r[1];
        });
        int counter = 0;
        int totalUnits = 0;
        int k, v;
        for (const auto &i : boxTypes) {
            k = i[0];
            v = i[1];
            if (counter + k == truckSize) {
                totalUnits += k * v;
                break;
            }
            else if (counter + k > truckSize) {
                totalUnits += (truckSize - counter) * v;
                break;
            }
            else {
                totalUnits += k * v;
                counter += k;
            }
        }
        return totalUnits;
    }
};