// https://www.nowcoder.com/practice/11b018d042444d4d9ca4914c7b84a968

class Joseph {
public:
    int getResult(int n, int m) {
        // write code here
        int s = 0;
        for (int i = 2; i <= n; i++)
            s = (s + m) % i;
        return s + 1;
    }
};