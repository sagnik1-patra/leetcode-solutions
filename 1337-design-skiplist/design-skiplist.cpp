class Skiplist {
    
    struct Node {
        int val;
        vector<Node*> forward;
        
        Node(int v, int level) {
            val = v;
            forward.resize(level, nullptr);
        }
    };
    
    const int MAX_LEVEL = 16;
    const double P = 0.5;
    
    Node* head;
    int level;
    
public:
    
    Skiplist() {
        level = 1;
        head = new Node(-1, MAX_LEVEL);
    }
    
    int randomLevel() {
        int lvl = 1;
        while((double)rand()/RAND_MAX < P && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }
    
    bool search(int target) {
        Node* curr = head;
        
        for(int i = level - 1; i >= 0; i--) {
            while(curr->forward[i] && curr->forward[i]->val < target)
                curr = curr->forward[i];
        }
        
        curr = curr->forward[0];
        return curr && curr->val == target;
    }
    
    void add(int num) {
        vector<Node*> update(MAX_LEVEL);
        Node* curr = head;
        
        for(int i = level - 1; i >= 0; i--) {
            while(curr->forward[i] && curr->forward[i]->val < num)
                curr = curr->forward[i];
            update[i] = curr;
        }
        
        int lvl = randomLevel();
        
        if(lvl > level) {
            for(int i = level; i < lvl; i++)
                update[i] = head;
            level = lvl;
        }
        
        Node* newNode = new Node(num, lvl);
        
        for(int i = 0; i < lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<Node*> update(MAX_LEVEL);
        Node* curr = head;
        
        for(int i = level - 1; i >= 0; i--) {
            while(curr->forward[i] && curr->forward[i]->val < num)
                curr = curr->forward[i];
            update[i] = curr;
        }
        
        curr = curr->forward[0];
        
        if(!curr || curr->val != num)
            return false;
        
        for(int i = 0; i < level; i++) {
            if(update[i]->forward[i] != curr)
                break;
            update[i]->forward[i] = curr->forward[i];
        }
        
        while(level > 1 && head->forward[level-1] == nullptr)
            level--;
        
        return true;
    }
};