class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = (int)arr.size();
        int counter = 0;
        auto iter = arr.begin();
        while (counter < n) {
            if (*iter != 0) {
                ++counter;
                ++iter;
            } else {
                iter = arr.insert(iter, 0);
                ++iter;
                ++iter;
                counter += 1;
            }
        }
        arr.erase(arr.begin() + n, arr.end());
    }
};