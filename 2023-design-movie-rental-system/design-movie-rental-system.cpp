
class MovieRentingSystem {
public:
    // movie -> set of {price, shop}
    unordered_map<int, set<pair<int, int>>> available;

    // {price, shop, movie}
    set<tuple<int, int, int>> rented;

    // {shop, movie} -> price
    map<pair<int, int>, int> prices;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];

            available[movie].insert({price, shop});
            prices[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;

        for (auto& p : available[movie]) {
            if (result.size() == 5)
                break;

            result.push_back(p.second);
        }

        return result;
    }

    void rent(int shop, int movie) {
        int price = prices[{shop, movie}];

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = prices[{shop, movie}];

        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;

        for (auto& [price, shop, movie] : rented) {
            if (result.size() == 5)
                break;

            result.push_back({shop, movie});
        }

        return result;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated
 * and called as such:
 * MovieRentingSystem* obj =
 *     new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop, movie);
 * obj->drop(shop, movie);
 * vector<vector<int>> param_4 = obj->report();
 */
