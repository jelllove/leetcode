struct LinkedListNode {
    int key;
    int val;
    int freq;
    LinkedListNode *next;
    LinkedListNode *pred;
    LinkedListNode(int key, int val) {
        this->key = key;
        this->val = val;
        freq = 1;
        next = NULL;
        pred = NULL;
    }
};

class LinkedList {
private:
    int size;
    LinkedListNode *head;
    LinkedListNode *tail;

public:
    LinkedList() {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    LinkedListNode *pop(LinkedListNode *node) {
        // Pop the node and return it
        LinkedListNode *res = node;
        if (node == head) {
            if (head == tail) {
                head = tail = NULL;
            } else {
                head->next->pred = NULL;
                head = head->next;
            }
        } else if (node == tail) {
            tail->pred->next = NULL;
            tail = tail->pred;
        } else {
            node->next->pred = node->pred;
            node->pred->next = node->next;
        }
        size -= 1;
        return node;
    }

    void push(LinkedListNode *node) {
        // Push the node to head
        if (head == NULL) {
            head = tail = node;
        } else {
            node->next = head;
            node->pred = NULL;
            head->pred = node;
            head = node;
        }
        size += 1;
    }

    bool empty() { return size == 0; }

    LinkedListNode *getTail() { return tail; }
};

class LFUCache {
private:
    unordered_map<int, LinkedListNode *> key_table;
    unordered_map<int, LinkedList> freq_table;
    int size;
    int capacity;
    int min_freq;

public:
    LFUCache(int capacity) {
        size = 0;
        this->capacity = capacity;
        min_freq = 0;
    }

    int get(int key) {
        if (key_table[key] == NULL)
            return -1;
        int value = key_table[key]->val;
        update(key, value);
        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;
        if (key_table[key] != NULL) {
            update(key, value);
        } else {
            LinkedListNode *node = new LinkedListNode(key, value);
            if (size < capacity) {
                push(node);
            } else if (size == capacity) {
                LinkedListNode *to_delete =
                    freq_table[min_freq].pop(freq_table[min_freq].getTail());
                key_table[to_delete->key] = NULL;
                size -= 1;
                push(node);
            }
            key_table[key] = node;
            min_freq = 1;
            size += 1;
        }
    }

    void update(int key, int value) {
        // Pop the node and push into new list
        LinkedListNode *node = key_table[key];
        node->val = value;
        node = freq_table[node->freq].pop(node);
        if (min_freq == node->freq && freq_table[node->freq].empty())
            min_freq += 1;
        node->freq += 1;
        push(node);
    }

    void push(LinkedListNode *node) {
        if (freq_table.find(node->freq) == freq_table.end())
            freq_table[node->freq] = LinkedList();
        freq_table[node->freq].push(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */