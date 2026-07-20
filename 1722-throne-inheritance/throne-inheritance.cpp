class ThroneInheritance {
private:
    unordered_map<string, vector<string>> children;
    unordered_set<string> dead;
    string king;

public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(string person, vector<string> &order) {
        if (!dead.count(person)) {
            order.push_back(person);
        }
        
        for (string &child : children[person]) {
            dfs(child, order);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }
};