class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int counter = 0;
        int i = 0, j = (int)people.size()-1;
        while (i <= j) {
            ++counter;
            if (i == j) {
                break;
            }
            else {
                if (people[i] + people[j] <= limit) {
                    ++i;
                }
                --j;
            }
        }
        return counter;
    }
};