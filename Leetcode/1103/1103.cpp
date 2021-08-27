class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int currentCandy = 1;
        int currentIndex = 0;
        while (candies > 0) {
            if (candies < currentCandy) {
                ans[currentIndex] += candies;
                candies = 0;
            } else {
                ans[currentIndex] += currentCandy;
                candies -= currentCandy;
                ++currentCandy;
                ++currentIndex;
                if (currentIndex == num_people) {
                    currentIndex = 0;
                }   
            }
        }
        return ans;
    }
};