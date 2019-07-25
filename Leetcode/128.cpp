class Solution {
public:
    int longestConsecutive(vector<int>& A) {

        int len = static_cast<int>(A.size());
        if (len <= 1)
            return len;

        unordered_set<int> a (A.begin(), A.end());
        int res = 1;
        int prev, next;

        for (auto i : A) {

            if (a.find(i) == a.end())
                continue;

            a.erase(i);
            prev = i - 1;
            next = i + 1;
            while (a.find(prev) != a.end()) {
                a.erase(prev);
                --prev;
            }
            while (a.find(next) != a.end()) {
                a.erase(next);
                ++next;
            }
            res = max(res, next - prev - 1);
        }

        return res;
    }
};