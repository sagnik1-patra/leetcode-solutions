/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;

        Node dummy; // helper to simplify edge cases
        Node* prev = &dummy;

        std::stack<Node*> st;
        st.push(head);

        while (!st.empty()) {
            Node* cur = st.top(); st.pop();

            // wire prev <-> cur
            prev->next = cur;
            cur->prev = prev;

            // push next first so child is processed before it
            if (cur->next) st.push(cur->next);
            if (cur->child) {
                st.push(cur->child);
                cur->child = nullptr; // must nullify child
            }

            prev = cur;
        }

        // detach dummy
        dummy.next->prev = nullptr;
        return dummy.next;
    }
};
