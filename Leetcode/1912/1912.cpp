constexpr int MAXN = 1e4+5;
constexpr size_t K = 5;

class MovieRentingSystem {
private:
    struct Pair0 {
        int shop, price;
        Pair0 (int shop, int price) : shop(shop), price(price) {}
        bool operator < (const Pair0 &o) const {
            if (price == o.price) {
                return shop < o.shop;
            }
            return price < o.price;
        };
    };
    struct Pair1 {
        int shop, price;
        Pair1 (int shop, int price) : shop(shop), price(price) {}
        bool operator < (const Pair1 &o) const {
            return shop < o.shop;
        }
    };
    struct Pair2 {
        int movie, shop, price;
        Pair2(int movie, int shop, int price) : movie(movie), shop(shop), price(price) {}
        bool operator < (const Pair2 &o) const {
            if (price == o.price) {
                if (shop == o.shop) {
                    return movie < o.movie;
                }
                return shop < o.shop;
            }
            return price < o.price;
        }
    };
    set<Pair0, less<> > movie2shops[MAXN]{};
    set<Pair1, less<> > unrented[MAXN]{};
    set<Pair1, less<> > rented[MAXN]{};
    set<Pair2, less<> > rentedSet;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        int shop, movie, price;
        for (const auto &i : entries) {
            shop = i[0];
            movie = i[1];
            price = i[2];
            movie2shops[movie].insert(Pair0(shop, price));
            unrented[movie].insert(Pair1(shop, price));
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        if (movie2shops[movie].size() < K) {
            for (const auto &i : movie2shops[movie]) {
                ans.emplace_back(i.shop);
            }
        }
        else {
            auto iter = movie2shops[movie].begin();
            for (size_t i = 0; i != K; ++i) {
                ans.emplace_back(iter->shop);
                ++iter;
            }
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        auto iter = unrented[movie].lower_bound(Pair1(shop, 0));
        movie2shops[movie].erase(Pair0(shop, iter->price));
        rented[movie].insert(*iter);
        rentedSet.insert(Pair2(movie, shop, iter->price));
        unrented[movie].erase(iter);
    }
    
    void drop(int shop, int movie) {
        auto iter = rented[movie].lower_bound(Pair1(shop, 0));
        movie2shops[movie].insert(Pair0(shop, iter->price));
        unrented[movie].insert(Pair1(shop, iter->price));
        rentedSet.erase(Pair2(movie, shop, iter->price));
        rented[movie].erase(iter);
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        if (rentedSet.size() < K) {
            for (const auto &i : rentedSet) {
                ans.emplace_back(vector<int>{i.shop, i.movie});
            }
        }
        else {
            auto it = rentedSet.begin();
            for (size_t i = 0; i != K; ++i) {
                ans.emplace_back(vector<int>{it->shop, it->movie});
                ++it;
            }
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */