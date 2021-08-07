class Trie {

private:
    Trie* next[256] = {nullptr};//因为char的范围是0-255
    bool isEnd = false;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *root = (Trie *)this;
        
        for (auto &c : word)
        {
            if (root->next[c] == nullptr)
                root->next[c] = new Trie();
            root = root->next[c];
        }
        
        root->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *root = (Trie *)this;
        
        for (auto &c : word)
        {
            if (root->next[c] == nullptr)
                return false;
            root = root->next[c];
        }
        
        return root->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = (Trie *)this;
        
        for (auto &c : prefix)
        {
            if (root->next[c] == nullptr)
                return false;
            root = root->next[c];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */