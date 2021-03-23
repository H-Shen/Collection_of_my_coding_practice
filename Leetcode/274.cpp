class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<>());
        int n = (int)citations.size();
        vector<int> minFromLeft(n);
        int temp;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                temp = citations.at(i);
            } else {
                temp = min(temp, citations.at(i));
            }
            minFromLeft.at(i) = temp;
        }
        vector<int> maxFromRight(n);
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                temp = citations.at(i);
            } else {
                temp = max(temp, citations.at(i));
            }
            maxFromRight.at(i) = temp;
        }
        int answer = -1;
        for (int h = 0; h <= n; ++h) {
            if (h == 0) {
                if (citations.front() <= 0) {
                    answer = max(answer, h);
                }
            }
            else if (h == n) {
                if (citations.back() >= n) {
                    answer = max(answer, h);
                }
            }
            else {
                if (minFromLeft.at(h - 1) >= h && maxFromRight.at(h) <= h) {
                    answer = max(answer, h);
                }
            }
        }
        
        return answer;
    }
};