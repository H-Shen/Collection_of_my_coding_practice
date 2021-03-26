class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int counter = 0;
        for (const auto &i : arr1) {
            if (all_of(arr2.begin(), arr2.end(), [&](const int &val){
                return abs(i - val) > d;
            })) ++counter;
        }
        return counter;
    }
};