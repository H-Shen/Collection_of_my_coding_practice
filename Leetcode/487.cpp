class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = (int)nums.size();
        vector<pair<int,int>> vec;
        int last = -1;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (last == -1) {
                last = nums[i];
                ++counter;
                continue;
            }
            if (last == 1) {
                if (nums[i] == 1) {
                    ++counter;
                } else {
                    vec.emplace_back(last, counter);
                    last = nums[i];
                    counter = 1;
                }
            }
            else {
                if (nums[i] == 0) {
                    ++counter;
                } else {
                    vec.emplace_back(last, counter);
                    last = nums[i];
                    counter = 1;
                }
            }
        }
        if (counter > 0) {
            vec.emplace_back(last, counter);
        }
        int maxSize = 1;
        int length = (int)vec.size();
        for (int i = 0; i < length; ++i) {
            if (vec[i].first == 1) {
                maxSize = max(maxSize, vec[i].second);
            }
        }
        int temp1, temp2;
        for (int i = 0; i < length; ++i) {
            if (vec[i].first == 0) {
                if (vec[i].second == 1) {
                    if (i-1 >= 0 && i-1 < length) {
                        temp1 = vec[i-1].second;
                    } else {
                        temp1 = 0;
                    }
                    if (i+1 >= 0 && i+1 < length) {
                        temp2 = vec[i+1].second;
                    } else {
                        temp2 = 0;
                    }
                    maxSize = max(maxSize, temp1+temp2+1);
                }
                else {
                    if (i-1 >= 0 && i-1 < length) {
                        maxSize = max(maxSize, vec[i-1].second+1);
                    }
                    if (i+1 >= 0 && i+1 < length) {
                        maxSize = max(maxSize, vec[i+1].second+1);
                    }
                }
            }
        }
        return maxSize;
    }
};