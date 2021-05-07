class Solution {
public:
    bool isAnagram(string s, string t) {
        
        //Method 1: using the hash
        /*
        unordered_map<char, int> um_s;
        unordered_map<char, int> um_t;
        
        for (auto &it_s : s)
        {
            um_s[it_s]++;
        }
        
        for (auto &it_t : t)
        {
            um_t[it_t]++;
        }
        
        return um_t == um_s;
        */
        //Method 2: using the vector
        /*
        vector<int> table(26, 0);
        for (auto &its : s)
        {
            table[its - 'a']++;
        }
        
        
        for (auto &itt : t)
        {
            table[itt - 'a']--;
        }
        
        return table == vector<int>(26, 0);
        */
        
        //Method 3: deep optimize
        if (s.size() != t.size())
            return false;
        
        int table[26] = {0};
        int blank_table[26] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            table[s[i] - 'a']++;
            table[t[i] - 'a']--;
        }
        
        return memcmp(table, blank_table, sizeof(table)) == 0;
        
    }
};