class Solution {
public:
    int answer;
    int target;

    void updateAnswer(int cost) {
        if (abs(cost - target) < abs(answer - target) ||
            (abs(cost - target) == abs(answer - target) && cost < answer)) {
            answer = cost;
        }
    }

    void dfs(vector<int>& toppingCosts, int index, int cost) {
        updateAnswer(cost);

        if (index == toppingCosts.size()) {
            return;
        }

        // Prune if already above target and cannot improve
        if (cost > target && cost - target > abs(answer - target)) {
            return;
        }

        // Take 0 of this topping
        dfs(toppingCosts, index + 1, cost);

        // Take 1 of this topping
        dfs(toppingCosts, index + 1,
            cost + toppingCosts[index]);

        // Take 2 of this topping
        dfs(toppingCosts, index + 1,
            cost + 2 * toppingCosts[index]);
    }

    int closestCost(vector<int>& baseCosts,
                    vector<int>& toppingCosts,
                    int target) {
        this->target = target;
        answer = baseCosts[0];

        for (int base : baseCosts) {
            dfs(toppingCosts, 0, base);
        }

        return answer;
    }
};