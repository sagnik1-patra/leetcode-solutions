
class Solution {
public:
    struct Node {
        map<string, Node*> children;
        int id = 0;
    };

    Node* root = new Node();

    map<vector<pair<string, int>>, int> ids;
    unordered_map<int, int> freq;
    int nextId = 1;

    int serialize(Node* node) {
        if (node->children.empty()) {
            return 0;
        }

        vector<pair<string, int>> key;

        for (auto& [name, child] : node->children) {
            int childId = serialize(child);
            key.push_back({name, childId});
        }

        if (!ids.count(key)) {
            ids[key] = nextId++;
        }

        node->id = ids[key];
        freq[node->id]++;

        return node->id;
    }

    void dfs(Node* node, vector<string>& path,
             vector<vector<string>>& ans) {

        for (auto& [name, child] : node->children) {

            if (child->id != 0 && freq[child->id] > 1) {
                continue;
            }

            path.push_back(name);
            ans.push_back(path);

            dfs(child, path, ans);

            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(
        vector<vector<string>>& paths) {

        for (auto& path : paths) {
            Node* curr = root;

            for (auto& folder : path) {
                if (!curr->children.count(folder)) {
                    curr->children[folder] = new Node();
                }

                curr = curr->children[folder];
            }
        }

        serialize(root);

        vector<vector<string>> ans;
        vector<string> path;

        dfs(root, path, ans);

        return ans;
    }
};
