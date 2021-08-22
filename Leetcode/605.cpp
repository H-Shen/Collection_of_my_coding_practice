class Solution {
public:
    int f(int n) {
        if (n & 1) {
            return (n-1)/2;
        }
        return n/2-1;
    }
    int g(int n) {
        if (n & 1) {
            return (n-1)/2;
        }
        return n/2;
    }
    int h(int n) {
        if (n & 1) {
            return (n+1)/2;
        }
        return n/2;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = (int)flowerbed.size();
        if (count(flowerbed.begin(),flowerbed.end(),1) == 0) {
            return h(length) >= n;
        }
        int sum = 0;
        int i = 0;
        int counter = 0;
        for (; i < length && flowerbed[i] != 1; ++i) {
            ++counter;
        }
        if (counter > 0) {
            sum += g(counter);
        }
        int j = length-1;
        counter = 0;
        for (; j >= 0 && flowerbed[j] != 1; --j) {
            ++counter;
        }
        if (counter > 0) {
            sum += g(counter);
        }
        counter = 0;
        for (; i < j; ++i) {
            if (flowerbed[i] == 0) {
                ++counter;
            } else {
                if (counter > 0) {
                    sum += f(counter);
                    counter = 0;
                }
            }
        }
        if (counter > 0) {
            sum += f(counter);
        }
        return sum >= n;
    }
};