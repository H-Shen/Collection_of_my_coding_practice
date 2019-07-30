// https://www.nowcoder.com/practice/091c2f1cf441484f81696f08328b06cd

class Rearrange {
public:
    vector<int> findSegment(vector<int> A, int n) {
        // write code here
        vector<int> A_copy = A;
        sort(A_copy.begin(), A_copy.end());
        int startPos = 0, endPos = n - 1;
        while (startPos < n) {
            if (A_copy[startPos] != A[startPos]) {
                break;
            }
            ++startPos;
        }
        while (endPos >= 0) {
            if (A_copy[endPos] != A[endPos]) {
                break;
            }
            endPos--;
        }
        if (endPos == -1) {
            startPos = 0;
            endPos = 0;
        }
        return {startPos, endPos};
    }
};