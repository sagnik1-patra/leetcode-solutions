class LFUCache {
    struct Node {
        int key, val, freq;
        list<int>::iterator it; // position in the freq list
    };

    int cap, sz, minFreq;
    unordered_map<int, Node> nodes;         // key -> Node
    unordered_map<int, list<int>> buckets;  // freq -> keys in LRU order (front = MRU)

    void touch(Node &nd) {
        // move key from freq list nd.freq to (nd.freq+1) list, as MRU
        int f = nd.freq;
        auto &lst = buckets[f];
        lst.erase(nd.it);
        if (lst.empty()) {
            buckets.erase(f);
            if (minFreq == f) ++minFreq;
        }
        nd.freq = f + 1;
        auto &nxt = buckets[nd.freq];
        nxt.push_front(nd.key);
        nd.it = nxt.begin();
    }

public:
    LFUCache(int capacity) : cap(capacity), sz(0), minFreq(0) {}

    int get(int key) {
        auto it = nodes.find(key);
        if (it == nodes.end() || cap == 0) return -1;
        touch(it->second);
        return it->second.val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        auto it = nodes.find(key);
        if (it != nodes.end()) {
            // update value, bump freq (recent use)
            it->second.val = value;
            touch(it->second);
            return;
        }

        // need space?
        if (sz == cap) {
            // evict LFU, and among those, LRU (tail of buckets[minFreq])
            auto &lst = buckets[minFreq];
            int evictKey = lst.back();
            lst.pop_back();
            if (lst.empty()) buckets.erase(minFreq);
            nodes.erase(evictKey);
            --sz;
        }

        // insert new key with freq = 1 (due to put)
        minFreq = 1;
        auto &lst = buckets[minFreq];
        lst.push_front(key);
        Node nd{key, value, 1, lst.begin()};
        nodes.emplace(key, std::move(nd));
        ++sz;
    }
};
