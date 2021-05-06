class Solution {
public:
    int firstUniqChar(string s) {
        //Method 1: using the hash + pair
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
    }
};