class Solution {
public:
    // dfs + binary search(greedy)
    vector<pair<int,string>> vec;
    string result;
    void dfs(int num) {
        if (num == 0) {
            return;
        }
        pair<int, string> temp;
        temp.first = num;
        auto iter = lower_bound(vec.begin(),vec.end(),temp,[](const auto &l, const auto &r) {
            return l.first < r.first; 
        });
        if (iter->first == num) {
            result += iter->second;
        } else {
            --iter;
            result += iter->second;
        }
        dfs(num - iter->first);
    }
    string intToRoman(int num) {
        vec.emplace_back(1,"I");
        vec.emplace_back(5,"V");
        vec.emplace_back(10,"X");
        vec.emplace_back(50,"L");
        vec.emplace_back(100,"C");
        vec.emplace_back(500,"D");
        vec.emplace_back(1000,"M");
        vec.emplace_back(4,"IV");
        vec.emplace_back(9,"IX");
        vec.emplace_back(40,"XL");
        vec.emplace_back(90,"XC");
        vec.emplace_back(400,"CD");
        vec.emplace_back(900,"CM");
        sort(vec.begin(),vec.end(),[](const auto&l, const auto&r) {
            return l.first < r.first;
        });
        result.clear();
        dfs(num);
        return result;
    }
};