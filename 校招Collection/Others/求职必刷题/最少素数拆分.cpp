class Solution {
public:
    /**
     * 判断给定的正整数最少能表示成多少个素数的和
     * @param N int整型 给定的正整数
     * @return int整型
     */
    int MinPrimeSum(int N) {
        // write code here
        if (N == 2 || N == 3) return 1;
        if (N % 2 == 0) return 2;
        bool flag = true;
        for (int i = 2; i * i <= N; ++i) {
            if (N % i == 0) {
                flag = false;
                break;
            }
        }
        if  (flag) {
            return 1;
        }
        int M = N - 2;
        for (int i = 2; i * i <= M; ++i) {
            if (M % i == 0) {
                return 3;
            }
        }
        return 2;
    }
};