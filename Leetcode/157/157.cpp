/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int counter = 0;
        while (n >= 4) {
            int temp = read4(buf);
            n -= temp;
            buf += temp;
            counter += temp;
            if (temp < 4) {
                return counter;
            }
        }
        if (n > 0) {
            int temp = read4(buf);
            counter += min(temp,n);
            buf += min(temp,n); // add the smaller one to avoid overflow
        }
        return counter;
    }
};