class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        // Years range from 1950 to 2050
        int population[101] = {0};

        // Mark population changes
        for (auto &log : logs) {
            int birth = log[0];
            int death = log[1];

            population[birth - 1950]++;
            population[death - 1950]--;
        }

        int currentPopulation = 0;
        int maxPopulation = 0;
        int answerYear = 1950;

        // Prefix sum gives population for each year
        for (int i = 0; i < 101; i++) {
            currentPopulation += population[i];

            if (currentPopulation > maxPopulation) {
                maxPopulation = currentPopulation;
                answerYear = 1950 + i;
            }
        }

        return answerYear;
    }
};