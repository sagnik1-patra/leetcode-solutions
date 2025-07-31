class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* curr = root;
        Node* head = nullptr;  // Head of the next level
        Node* prev = nullptr;  // The previous node on the next level

        while (curr) {
            while (curr) {
                if (curr->left) {
                    if (prev) prev->next = curr->left;
                    else head = curr->left;
                    prev = curr->left;
                }
                if (curr->right) {
                    if (prev) prev->next = curr->right;
                    else head = curr->right;
                    prev = curr->right;
                }
                curr = curr->next;
            }
            curr = head;
            head = nullptr;
            prev = nullptr;
        }

        return root;
    }
};
