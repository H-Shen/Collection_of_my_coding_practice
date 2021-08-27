class SparseVector {
public:
    vector<pair<int,int> > v;
    SparseVector(vector<int> &nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                v.emplace_back(nums[i],i);
            }
        }
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;
        auto it1 = v.begin();
        auto it2 = vec.v.begin();
        while (it1 != v.end() && it2 != vec.v.end()) {
            if (it1->second == it2->second) {
                sum += (it1->first) * (it2->first);
                ++it1;
                ++it2;
            }
            else if (it1->second < it2->second) {
                ++it1;
            }
            else {
                ++it2;
            }
        }
        return sum;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);