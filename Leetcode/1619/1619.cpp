class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = (int)arr.size();
        int counter = n / 20;
        int startIndex = counter;
        int endIndex = n - counter - 1;
        double result = 0.0;
        for (int i = startIndex; i <= endIndex; ++i) {
            result += arr.at(i);
        }
        return result / (endIndex - startIndex + 1);
    }
};