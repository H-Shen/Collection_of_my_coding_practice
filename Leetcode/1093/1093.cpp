class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        using ll = long long;
        ll minVal = 300;
        ll maxVal = -1;
        ll sum = 0;
        ll n = 0;
        ll maxFreq = -1;
        ll kWithMaxFreq = 0;
        for (ll i = 0; i < 256; ++i) {
            if (count.at(i) > 0) {
                minVal = min(minVal, i);
                maxVal = max(maxVal, i);
                sum += i * count.at(i);
                n += count.at(i);
                if (count.at(i) > maxFreq) {
                    maxFreq = count.at(i);
                    kWithMaxFreq = i;
                }
            }
        }
        ll mid = 0;
        double mid_val = -1.0;
        if (n % 2 == 0) {
            ll left = n / 2;
            ll right = left + 1;
            ll n_ = 0;
            ll left_val = -1;
            ll right_val = -1;
            for (ll i = 0; i < 256; ++i) {
                if (count.at(i) > 0) {
                    n_ += count.at(i);
                    if (n_ < left) {

                    } else if (n_ == left) {
                        left_val = i;
                    } else if (n_ == right) {
                        right_val = i;
                    } else {
                        if (left_val == -1) {
                            left_val = i;
                        }
                        if (right_val == -1) {
                            right_val = i;
                        }
                    }
                }
                if (left_val != -1 && right_val != -1) {
                    mid_val = (left_val + right_val) / 2.0;
                    break;
                }
            }
        } else {
            mid = (n + 1) / 2;
            int n_ = 0;
            for (int i = 0; i < 256; ++i) {
                if (count.at(i) > 0) {
                    n_ += count.at(i);
                    if (n_ < mid) {

                    } else if (n_ == mid) {
                        mid_val = i;
                        break;
                    } else {
                        if (mid_val < 0.0) {
                            mid_val = i;
                            break;
                        }
                    }
                }
            }
        }
        vector<double> result = {
            minVal * 1.0,
            maxVal * 1.0,
            sum * 1.0 / n,
            mid_val,
            kWithMaxFreq * 1.0
        };
        return result;
    }
};