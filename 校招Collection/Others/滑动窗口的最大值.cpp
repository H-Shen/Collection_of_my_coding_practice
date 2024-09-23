// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788

class Solution {
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size) {
        int n = static_cast<int>(num.size());
        int k = (int) size;
        vector<int> res;

        if (k > n || n == 0 || k == 0) {        //HANDLE EXCEPTIONS
            return res;
        }

        int i;
        deque<int> A(static_cast<unsigned long>(k));

        for (i = 0; i < k; i++) {   //HANDLE THE FIRST K ELEMENTS AND SAVE THE MAX ONE TO THE DEQUE
            while ((!A.empty()) && num[i] >= num[A.back()]) {
                A.pop_back();
            }
            A.push_back(i);
        }

        for (; i < n; i++) {
            res.push_back(num[A.front()]);

            while ((!A.empty()) && A.front() <= i - k) {
                A.pop_front();
            }

            while ((!A.empty()) && num[i] > num[A.back()]) {
                A.pop_back();
            }
            A.push_back(i);
        }
        res.push_back(num[A.front()]);
        return res;
    }
};