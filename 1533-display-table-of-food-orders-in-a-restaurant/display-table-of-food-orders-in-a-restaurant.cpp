class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foodItems;
        map<int, map<string, int>> tableOrders;

        for (auto& order : orders) {
            int table = stoi(order[1]);
            string food = order[2];

            foodItems.insert(food);
            tableOrders[table][food]++;
        }

        vector<vector<string>> ans;

        vector<string> header;
        header.push_back("Table");

        for (string food : foodItems) {
            header.push_back(food);
        }

        ans.push_back(header);

        for (auto& table : tableOrders) {
            vector<string> row;
            row.push_back(to_string(table.first));

            for (string food : foodItems) {
                row.push_back(to_string(table.second[food]));
            }

            ans.push_back(row);
        }

        return ans;
    }
};