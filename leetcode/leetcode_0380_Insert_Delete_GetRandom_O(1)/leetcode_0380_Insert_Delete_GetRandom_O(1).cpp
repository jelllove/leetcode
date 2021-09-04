
class RandomizedSet {
public:

/** Initialize your data structure here. */
unordered_map<int,int> mp;
RandomizedSet() {
    
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool insert(int val) {
    if(mp.find(val) != mp.end()) return false;
    mp[val] = 1;
    return true;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool remove(int val) {
    if(mp.find(val) == mp.end()) return false;
    mp.erase(val);
    return true;
}

/** Get a random element from the set. */
int getRandom() {
    int t = rand() % mp.size();
    auto it = mp.begin();
    for(int i = 0; i < t; i++) {
        it++;
    }
    return it->first;
}
};