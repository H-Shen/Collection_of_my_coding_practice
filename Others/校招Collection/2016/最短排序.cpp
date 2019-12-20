// https://www.nowcoder.com/practice/a6926700bd424820bd73777f1cb2ef60

class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        // write code here
        vector<int> A_copy = A;
        sort(A_copy.begin(), A_copy.end());
        int startPos = 0, endPos = n - 1;
        while (startPos < n) {
            if (A_copy[startPos] != A[startPos]) {
                break;
            }
            startPos++;
        }
        while (endPos >= 0) {
            if (A_copy[endPos] != A[endPos]) {
                break;
            }
            --endPos;
        }
        if (endPos == -1) {
            return 0;
        }
        return endPos - startPos + 1;
    }
};