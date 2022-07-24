struct Pair {
    int rating;
    string food;
    Pair() = default;
    Pair(int rating, string food) : rating(rating), food(move(food)) {}
    bool operator < (const Pair& obj) const {
        if (rating == obj.rating) {
            return food < obj.food;
        }
        return rating > obj.rating;
    }
};

class FoodRatings {
private:
    unordered_map<string, pair<string, int>> food2info;
    unordered_map<string, set<Pair>> cusine2info;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = (int)foods.size();
        for (int i = 0; i < n; ++i) {
            food2info.emplace(foods[i], make_pair(cuisines[i], ratings[i]));
            cusine2info[cuisines[i]].emplace(ratings[i], foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        pair<string,int>& p = food2info[food];
        int oldRating = p.second;
        if (oldRating != newRating) {
            set<Pair>& s = cusine2info[p.first];
            s.erase(Pair(oldRating, food));
            food2info[food].second = newRating;
            s.emplace(newRating, food);
        }
    }
    
    string highestRated(string cuisine) {
        return cusine2info[cuisine].begin()->food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */