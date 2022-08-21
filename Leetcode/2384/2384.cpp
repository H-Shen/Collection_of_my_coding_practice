constexpr int MAXN = 10;

class Solution {
public:
    string largestPalindromic(string num) {
        int freq[MAXN]{};
        for (auto&i : num) {
            ++freq[i - '0'];
        }
        deque<char> res;
        bool hasOdd = false;
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] & 1) {
                hasOdd = true;
                break;
            }
        }
        if (!hasOdd) {
            for (int i = 0; i < MAXN; ++i) {
                while (freq[i] > 0) {
                    res.push_back(i + '0');
                    res.push_front(i + '0');
                    freq[i] -= 2;
                }
            }
        }
        else {
            int maxVal = -1;
            for (int i = 0; i < MAXN; ++i) {
                if (freq[i] & 1) {
                    maxVal = max(maxVal, i);
                }
            }
            res.push_back(maxVal + '0');
            --freq[maxVal];
            for (int i = 0; i < MAXN; ++i) {
                if (freq[i] & 1) {
                    --freq[i];
                }
                while (freq[i] > 0) {
                    res.push_back(i + '0');
                    res.push_front(i + '0');
                    freq[i] -= 2;
                }
            }
        }
        while (res.size() > 1 && res.front() == '0' && res.back() == '0') {
            res.pop_front();
            res.pop_back();
        }
        if (res.empty()) {
            res.push_back('0');
        }
        return string(res.begin(),res.end());
    }
};