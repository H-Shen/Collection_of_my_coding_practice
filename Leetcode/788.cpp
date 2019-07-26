class Solution {
public:
    int rotatedDigits(int N) {

        unordered_set<char> A0{'3', '4', '7'};
        unordered_set<char> A1{'0', '1', '8'};
        unordered_set<char> A2{'2', '5', '6', '9'};
        unordered_set<int> A3{0, 1, 3, 4, 7, 8};
        const int maxn = 6;
        bool haveAns;
        bool haveA1;
        bool haveA2;

        char s[maxn];
        int cnt = 0;

        for (int i = 1; i <= N; ++i) {
            haveAns = true;

            //1-9
            if (i >= 1 && i <= 9 && A3.find(i) == A3.end()) {
                ++cnt;
            }

            //10-10000
            else {
                sprintf(s, "%d", i);
                haveA1 = false;
                haveA2 = false;
                for (size_t j = 0; s[j] != '\0'; ++j) {
                    if (A0.find(s[j]) != A0.end()) {
                        haveAns = false;
                        break;
                    }
                    if (A1.find(s[j]) != A1.end()) {
                        haveA1 = true;
                    } else if (A2.find(s[j]) != A2.end()) {
                        haveA2 = true;
                    }
                }
                if (haveA1 && !haveA2) {
                    haveAns = false;
                }

                if (haveAns) {
                    ++cnt;
                }
            }

        }
        return cnt;
    }
};