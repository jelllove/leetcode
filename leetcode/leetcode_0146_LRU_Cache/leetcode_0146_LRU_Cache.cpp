
class LRUCache {
struct DLL
{
    DLL *prev = nullptr;
    DLL *next = nullptr;
    int key = 0;
    int value = 0;
    DLL()
    {
        
    }
    DLL(int k, int v)
    {
        key = k;
        value = v;
    }
};
private:
    //把一个结点从整个链路中移除
    void _remove(DLL *item)
    {
        item->next->prev = item->prev;
        item->prev->next = item->next;
        item->prev = nullptr;
        item->next = nullptr;
    }
    
    //把一个结点加到顶部
    void _add(DLL *item)
    {
        item->next = head.next;
        head.next->prev = item;
        head.next = item;
        item->prev = &head;
    }
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        head.prev = nullptr;
        head.next = &tail;
        tail.prev = &head;
        tail.next = nullptr;
    }
    
    int get(int key) {
        if (data.count(key) == 0)
        {
            return -1;
        }
        else
        {
            _remove(data[key]);
            _add(data[key]);
            
            return data[key]->value;
        }
    }
    
    void put(int key, int value) {
        
        
        if (data.count(key) != 0)
        {
            DLL *node = data[key];
            _remove(node);
            _add(node);
            node->value = value;
        }
        else
        {
            if (data.size() >= m_capacity)
            {
                DLL *removeNode = tail.prev;
                _remove(removeNode);
                data.erase(removeNode->key);
                delete removeNode;
            }
            
            DLL *node = new DLL(key, value);
            data[key] = node;
            _add(node);
        }
        
    }
    
private:
    //key + DLL
    unordered_map<int, DLL*> data;
    DLL head;
    DLL tail;
    int m_capacity = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */