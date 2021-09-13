class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if (s.size() == 0 || p.size() == 0 || p.size() > s.size())
            return {};
        
        vector<int> ans;
        
        vector<int> sHash(26, 0);
        vector<int> pHash(26, 0);
        
        for (int i = 0; i < p.size(); ++i)
        {
            ++sHash[s[i] - 'a'];
            ++pHash[p[i] - 'a'];
        }
        
        int pos = 0;
        int j = p.size() - 1;
        
        while (j < s.size())
        {
            if (sHash == pHash)
                ans.push_back(pos);
            ++j;
            if (j < s.size())
            {
                sHash[s[pos] - 'a']--;
                sHash[s[j] - 'a']++;
            }
            ++pos;
            
        }
        
        
        return ans;
        
    }
};