class Solution {
public:
    int firstUniqChar(string s) {
        //Method 1: using the hash + pair
        /*
        unordered_map<char, pair<int, int>> um;
        
        int i = 0;
        for (i = 0; i < s.size(); ++i)
        {
            if (um.count(s[i]) >= 1)
            {
                um[s[i]].second++;
            }
            else
            {
                um[s[i]] = {i, 1};
            }
        }
        
        for (i = 0; i < s.size(); ++i)
        {
            if (um[s[i]].second == 1)
                return i;
        }
        return -1;
        */
        
        //Method 2: using the hash only
        /*
        unordered_map<char, int> um;
        
        int i = 0;
        for (i = 0; i < s.size(); ++i)
        {
            um[s[i]]++;
        }
        
        for (i = 0; i < s.size(); ++i)
        {
            if (um[s[i]] == 1)
                return i;
        }
        return -1;
        */
        
        //Method 3: using the vector
        vector<int> vec(26, 0);
        
        int i = 0;
        for (i = 0; i < s.size(); ++i)
        {
            vec[s[i] - 'a']++;
        }
        
        for (i = 0; i < s.size(); ++i)
        {
            if (vec[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    
    
    }
};