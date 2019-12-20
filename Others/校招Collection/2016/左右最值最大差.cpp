// https://www.nowcoder.com/practice/f5805cc389394cf69d89b29c0430ff27

class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int maxVal = *max_element(A.begin(), A.end());
        return max(maxVal - A.front(), maxVal - A.back());
    }
};