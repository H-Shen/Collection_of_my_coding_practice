class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int counter = 0;
        auto it1 = players.begin();
        auto it2 = trainers.begin();
        while (true) {
            if (it1 == players.end()) {
                break;
            }
            if (it2 == trainers.end()) {
                break;
            }
            if (*it1 <= *it2) {
                ++counter;
                ++it1;
                ++it2;
            }
            else {
                ++it2;
            }
        }
        return counter;
    }
};