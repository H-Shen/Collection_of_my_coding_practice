// https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {

        multiset<int> pushVSet(pushV.begin(), pushV.end());
        multiset<int> popVSet(popV.begin(), popV.end());
        if (pushVSet != popVSet) {
            return false;
        }

        unordered_map<int, int> A;
        int order = 1;

        for (auto &ptr : pushV) {
            A[ptr] = order;
            order++;
        }

        int i = 0;
        order--;
        vector<int> popOrder(static_cast<unsigned long>(order));

        for (auto &ptr : popV) {
            popOrder[i] = A[ptr];
            i++;
        }

        int j;
        for (i = 0; i < order - 1; i++) {
            vector<int> tmp;
            for (j = i + 1; j < order; j++) {
                if (popOrder[i] > popOrder[j]) {
                    tmp.push_back(popOrder[j]);
                }
            }
            vector<int> tmpCopy(tmp.begin(), tmp.end());
            sort(tmpCopy.begin(), tmpCopy.end(), [](const int &x, const int &y) {
                return (x > y);
            });
            if (tmpCopy != tmp)
                return false;
        }

        return true;
    }
};