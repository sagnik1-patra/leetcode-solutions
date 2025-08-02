/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 1. Clone each node and insert it just after the original node
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // 2. Assign random pointers to the cloned nodes
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3. Detach the original and cloned lists
        Node* dummy = new Node(0);
        Node* copy = dummy;
        curr = head;
        while (curr) {
            copy->next = curr->next;
            curr->next = curr->next->next;
            copy = copy->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};