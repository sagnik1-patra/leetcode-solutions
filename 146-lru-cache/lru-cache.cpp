class LRUCache {
private:
    // Doubly Linked List Node
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Remove node from the list
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node at head
    void insertToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0); // dummy head
        tail = new Node(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insertToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insertToHead(node);
        } else {
            if (cache.size() >= capacity) {
                Node* lru = tail->prev;
                cache.erase(lru->key);
                remove(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insertToHead(newNode);
        }
    }
};
