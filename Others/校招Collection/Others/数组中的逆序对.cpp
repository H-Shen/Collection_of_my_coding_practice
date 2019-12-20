// https://www.nowcoder.com/practice/bb06495cc0154e90bbb18911fd581df6

class AntiOrder {
public:
    int count(vector<int> A, int n) {
        // write code here
        int i, j;
        int res = 0;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (A.at(i) > A.at(j)) {
                    ++res;
                }
            }
        }
        return res;
    }
};