class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxVal = 0;
        for (auto&s : sentences) {
            istringstream iss(s);
            int counter = 0;
            string str;
            do {
                iss >> str;
                ++counter;
            } while (iss);
            --counter;
            maxVal = max(maxVal, counter);
        }
        return maxVal;
    }
};