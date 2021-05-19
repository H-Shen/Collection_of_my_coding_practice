class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_set<string> foods;
        for (const auto &i : orders) {
            foods.insert(i[2]);
        }
        vector<string> foodsSorted(foods.begin(), foods.end());
        sort(foodsSorted.begin(), foodsSorted.end());
        unordered_map<int, unordered_map<string,int> > unmap;
        for (const auto &i : orders) {
            ++unmap[stoi(i[1])][i[2]];
        }
        vector<vector<string> > result;

        vector<string> title;
        title.emplace_back("Table");
        for (const auto &i : foodsSorted) {
            title.emplace_back(i);
        }
        result.emplace_back(title);
        
        for (auto &[k,v] : unmap) {
            vector<string> vec;
            vec.emplace_back(to_string(k));
            for (const auto &i : foodsSorted) {
                vec.emplace_back(to_string(v[i]));
            }
            result.emplace_back(vec);
        }
        sort(result.begin()+1, result.end(), [](const auto &l, const auto &r){
            return stoi(l[0]) < stoi(r[0]);
        });
        
        return result;
    }
};