class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        vector<int> negative, zero, positive;
        for (const auto &i : A) {
            if (i < 0) negative.emplace_back(i);
            else if (i == 0) zero.emplace_back(i);
            else positive.emplace_back(i);
        }
        int a = (int)negative.size();
        int b = (int)zero.size();
        int c = (int)positive.size();
        if (a >= K) {
            sort(negative.begin(), negative.end());
            for (int i = 0; i < K; ++i) {
                negative.at(i) = -negative.at(i);
            }
        }
        else {
            for (int i = 0; i < a; ++i) {
                negative.at(i) = -negative.at(i);
            }
            if (b > 0) {
                // nothing changed
            }
            else {
                if ((K - a) % 2 == 0) {
                    // nothing changed
                }
                else {
                    sort(negative.begin(), negative.end());
                    sort(positive.begin(), positive.end());
                    if (c > 0 && a > 0) {
                        if (negative[0] < positive[0]) {
                            negative[0] = -negative[0];
                        }
                        else {
                            positive[0] = -positive[0];
                        }
                    }
                    else if (c > 0 && a == 0) {
                        positive[0] = -positive[0];
                    }
                    else if (c == 0 && a > 0) {
                        negative[0] = -negative[0];
                    }
                    else {
                        // nothing changed
                    }
                }
            }
        }
        int sum = 0;
        for (const auto &i : negative) sum += i;
        for (const auto &i : zero) sum += i;
        for (const auto &i : positive) sum += i;
        return sum;
    }
};