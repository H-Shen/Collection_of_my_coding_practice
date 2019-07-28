class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {

        struct Pos {
            int min_list1_pos = 2000;
            int min_list2_pos = 2000;
        };

        unordered_set<string> list1_set(list1.begin(), list1.end());
        unordered_set<string> list2_set(list2.begin(), list2.end());
        unordered_map<string, Pos> A;
        for (auto it = list1_set.begin(); it != list1_set.end(); ++it) {
            if (list2_set.find(*it) != list2_set.end()) {
                A[*it];
            }
        }
        for (int i = 0; i < static_cast<int>(list1.size()); ++i) {
            if (A.find(list1[i]) != A.end()) {
                A[list1[i]].min_list1_pos = min(A[list1[i]].min_list1_pos, i);
            }
        }
        for (int i = 0; i < static_cast<int>(list2.size()); ++i) {
            if (A.find(list2[i]) != A.end()) {
                A[list2[i]].min_list2_pos = min(A[list2[i]].min_list2_pos, i);
            }
        }
        vector<string> res;
        int minIdxSum = 2000;
        for (auto it = A.cbegin(); it != A.cend(); ++it) {
            minIdxSum = min(minIdxSum, it->second.min_list1_pos + it->second.min_list2_pos);
        }
        for (auto it = A.cbegin(); it != A.cend(); ++it) {
            if (it->second.min_list1_pos + it->second.min_list2_pos == minIdxSum) {
                res.push_back(it->first);
            }
        }
        return res;
    }
};