// https://www.nowcoder.com/practice/c001f4e9820447189110da5e882aa158

class Solution {
public:
    int getUpMedian(vector<int> arr1, vector<int> arr2) {
        multiset<int> a;
        int i;
        int pos = 1;
        int len = arr1.size();
        int kth = len;
        for (i = 0; i < len; i++)
            a.insert(arr1[i]);
        for (i = 0; i < len; i++)
            a.insert(arr2[i]);
        for (auto it = a.begin(); it != a.end(); ++it) {
            if (pos == kth)
                return *it;
            pos++;
        }
        return -1;
    }
};