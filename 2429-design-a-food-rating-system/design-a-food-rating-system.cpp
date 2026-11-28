class FoodRatings {
private:
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;
    unordered_map<string, set<pair<int, string>>> cuisineFoods;

public:
    FoodRatings(vector<string>& foods,
                vector<string>& cuisines,
                vector<int>& ratings) {

        int n = foods.size();

        for (int i = 0; i < n; i++) {
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];

            cuisineFoods[cuisines[i]].insert(
                {-ratings[i], foods[i]}
            );
        }
    }

    void changeRating(string food, int newRating) {
        string cuisine = foodCuisine[food];
        int oldRating = foodRating[food];

        // Remove the old rating
        cuisineFoods[cuisine].erase({-oldRating, food});

        // Update the rating
        foodRating[food] = newRating;

        // Insert the new rating
        cuisineFoods[cuisine].insert({-newRating, food});
    }

    string highestRated(string cuisine) {
        return cuisineFoods[cuisine].begin()->second;
    }
};