class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    
    Node* head;  // dummy head
    int length;  // to track size

public:
    MyLinkedList() {
        head = new Node(0); // dummy node
        length = 0;
    }

    int get(int index) {
        if (index < 0 || index >= length) return -1;
        Node* curr = head->next;
        for (int i = 0; i < index; ++i)
            curr = curr->next;
        return curr->val;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(length, val);
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        Node* prev = head;
        for (int i = 0; i < index; ++i)
            prev = prev->next;
        Node* newNode = new Node(val);
        newNode->next = prev->next;
        prev->next = newNode;
        ++length;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        Node* prev = head;
        for (int i = 0; i < index; ++i)
            prev = prev->next;
        Node* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
        --length;
    }
};
