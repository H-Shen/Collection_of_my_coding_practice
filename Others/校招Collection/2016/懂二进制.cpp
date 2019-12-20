// https://www.nowcoder.com/practice/ba033b0d1c2f497da1dd04330cc003af

class Solution {
public:
    /**
     * 获得两个整形二进制表达位数不同的数量
     *
     * @param m 整数m
     * @param n 整数n
     * @return 整型
     */
    int countBitDiff(int m, int n) {

        int num = m ^n;
        int k = 0;
        int a;

        while (num != 0) {
            if (num & 1) {
                k++;
            }
            num >>= 1;
        }
        return k;
    }
};