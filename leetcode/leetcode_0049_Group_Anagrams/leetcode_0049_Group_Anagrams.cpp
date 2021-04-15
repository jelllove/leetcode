
typedef map<char, int> charHash;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        
        
        
        //Method 1: using the hashIndex + vector
        /*
        map<charHash, vector<string>> hashList;
          
        for (int i = 0; i < strs.size(); ++i)
        {
            charHash um;
            for (auto &s : strs[i])
            {
                um[s]++;
            }
            
            if (hashList.count(um) > 0)
                hashList[um].push_back(strs[i]);
            else
                hashList[um] = vector<string>{strs[i]};
        }
        
        vector<vector<string>> ret;
        
        for (auto &l : hashList)
        {
            ret.push_back(l.second);
        }
        
        return ret;
        */
        
        //Method 2: using the sort to sort all the word
        
        unordered_map<string, vector<string>> hashList;
        
        for (int i = 0; i < strs.size(); ++i)
        {
            string strTmp = strs[i];
            std::sort(strTmp.begin(), strTmp.end());
            
            if (hashList.count(strTmp) > 0)
                hashList[strTmp].push_back(strs[i]);
            else
                hashList[strTmp] = vector<string>{strs[i]};
        }
        
        vector<vector<string>> ans;
        
        for (auto &it : hashList)
        {
            ans.push_back(it.second);
        }
        
        return ans;
        
        
    }
};