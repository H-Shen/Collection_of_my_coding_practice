using ll = long long;

constexpr int MAXN = 105;

class Solution {
public:
    long long singleDivisorTriplet(vector<int>& nums) {
        int freq[MAXN]{};
        for (auto&i : nums) {
            ++freq[i];
        }
        ll counter = 0;
        vector<pair<int,int>> vec;
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] != 0) {
                vec.emplace_back(i,freq[i]);
            }
        }
        int n = (int)vec.size();
        int temp;
        int count;
        // Case 1: example: (1,2,2)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && vec[j].second > 1) {
                    temp = vec[i].first + vec[j].first + vec[j].first;
                    if (temp % vec[i].first == 0 && temp % vec[j].first != 0) {
                        counter += (ll)vec[i].second * vec[j].second * (vec[j].second-1) * 3;
                    }
                }
            }
        }
        // Case 2: example: (2,3,4)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && i != k && j != k) {
                        count = 0;
                        temp = vec[i].first + vec[j].first + vec[k].first;
                        if (temp % vec[i].first == 0) {
                            ++count;
                        }
                        if (temp % vec[j].first == 0) {
                            ++count;
                        }
                        if (temp % vec[k].first == 0) {
                            ++count;
                        }
                        if (count == 1) {
                            counter += (ll)vec[i].second * vec[j].second * vec[k].second;
                        }
                    }
                }
            }
        }
        return counter;
    }
};