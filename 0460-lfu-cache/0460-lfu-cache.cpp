class LFUCache {
public:

    class Node {
    public:
        int key;
        int val;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            val = v;
            freq = 1;

            prev = NULL;
            next = NULL;
        }
    };

    // key -> node
    unordered_map<int, Node*> m;

    // frequency -> DLL of nodes
    unordered_map<int, pair<Node*, Node*>> freqList;

    int limit;
    int minFreq;


    // Add node at front of a frequency list
    void addNode(Node* node) {

        int freq = node->freq;

        // If this frequency list doesn't exist
        if (freqList.find(freq) == freqList.end()) {

            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            freqList[freq] = {head, tail};
        }

        Node* head = freqList[freq].first;

        Node* oldnext = head->next;

        head->next = node;
        node->prev = head;

        node->next = oldnext;
        oldnext->prev = node;
    }


    // Delete node from its frequency list
    void delNode(Node* node) {

        Node* oldprev = node->prev;
        Node* oldnext = node->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }


    // Constructor
    LFUCache(int capacity) {

        limit = capacity;
        minFreq = 0;
    }


    int get(int key) {

        // Key doesn't exist
        if (m.find(key) == m.end()) {
            return -1;
        }

        Node* node = m[key];

        int ans = node->val;

        // Remove from old frequency list
        delNode(node);

        int oldFreq = node->freq;

        // If old frequency was minimum
        // and its list becomes empty
        Node* head = freqList[oldFreq].first;
        Node* tail = freqList[oldFreq].second;

        if (head->next == tail && minFreq == oldFreq) {
            minFreq++;
        }

        // Increase frequency
        node->freq++;

        // Add to new frequency list
        addNode(node);

        return ans;
    }


    void put(int key, int value) {

        // Capacity is 0
        if (limit == 0) {
            return;
        }


        // Key already exists
        if (m.find(key) != m.end()) {

            Node* node = m[key];

            // Update value
            node->val = value;

            // Increase frequency
            delNode(node);

            int oldFreq = node->freq;

            Node* head = freqList[oldFreq].first;
            Node* tail = freqList[oldFreq].second;

            if (head->next == tail && minFreq == oldFreq) {
                minFreq++;
            }

            node->freq++;

            addNode(node);

            return;
        }


        // Cache is full
        if (m.size() == limit) {

            // Get least frequently used list
            Node* head = freqList[minFreq].first;
            Node* tail = freqList[minFreq].second;

            // Last node = least recently used
            Node* oldnode = tail->prev;

            // Remove from list
            delNode(oldnode);

            // Remove from hashmap
            m.erase(oldnode->key);

            delete oldnode;
        }


        // Create new node
        Node* newnode = new Node(key, value);

        // New node has frequency = 1
        minFreq = 1;

        // Add to frequency 1 list
        addNode(newnode);

        // Add to hashmap
        m[key] = newnode;
    }
};