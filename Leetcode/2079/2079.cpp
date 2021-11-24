class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = (int)plants.size();
        int counter = 0;
        int rest = capacity;
        for (int i = 0; i < n; ++i) {
            if (rest < plants[i]) {
                counter += i * 2;
                rest = capacity;
            }
            counter++;
            rest -= plants[i];
        }
        return counter;
    }
};