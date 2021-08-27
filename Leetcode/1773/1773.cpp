class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int counter = 0;
        if (ruleKey == "type") {
            counter = count_if(items.begin(), items.end(), [&](const auto &o){return o[0] == ruleValue;});
        }
        else if (ruleKey == "color") {
            counter = count_if(items.begin(), items.end(), [&](const auto &o){return o[1] == ruleValue;});
        }
        else if (ruleKey == "name") {
            counter = count_if(items.begin(), items.end(), [&](const auto &o){return o[2] == ruleValue;});
        }
        return counter;
    }
};