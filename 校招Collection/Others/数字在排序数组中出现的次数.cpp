// https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2

class Solution {
public:
    int GetNumberOfK(vector<int> data, int k) {
        auto resultPair = equal_range(data.begin(), data.end(), k);
        return (resultPair.second - resultPair.first);
    }
};