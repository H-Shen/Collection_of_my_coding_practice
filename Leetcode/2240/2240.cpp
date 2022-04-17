class Solution {
public:
    // cost1 * x + cost2 * y = total
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2) {
            swap(cost1, cost2);
        }
        long long counter = 0;
        for (int x = 0; x * cost1 <= total; ++x) {
            int temp = total - x * cost1;
            if (temp >= cost2) {
                counter += (long long)(temp / cost2);
            }
            ++counter;
        }
        return counter;
    }
};