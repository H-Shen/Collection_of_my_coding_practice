class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = (int)arr.size();
        if (k >= n) {
            return *max_element(arr.begin(),arr.end());
        }
        list<int> A(arr.begin(),arr.end());
        int lastOne = -1;
        int counter = 0;
        int a, b;
        list<int>::iterator it1, it2;
        while (true) {
            it1 = A.begin();
            it2 = A.begin();
            advance(it2, 1);
            if (*it1 < *it2) {
                swap(*it1, *it2);
            }
            a = *it1;
            b = *it2;
            if (lastOne == -1) {
                lastOne = a;
                ++counter;
            }
            else if (lastOne == a) {
                ++counter;
            }
            else {
                lastOne = a;
                counter = 1;
            }
            if (counter == k) {
                return lastOne;
            }
            A.erase(it2);
            A.emplace_back(b);
        }
        return -1;
    }
};