class Solution {
public:
    
    bool dfs(string s, vector<string>& wordDict)
    {
        if (s == "")
            return true;
        
        for (auto &w : wordDict)
        {
            if (s.size() >= w.size() and s.substr(0, w.size()) == w)
            {
                if (dfs(s.substr(w.size(), s.size() - w.size()), wordDict))
                    return true;
            }
        }
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //Method 1: using the dfs, but time out
        //return dfs(s, wordDict);
        
        //Method 2: using the dp
        int i,j,n=s.length();
        vector<int>dp(n+1,0);
        dp[0]=1;
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        for(i=1;i<=n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(dp[j]==1 && set.count(s.substr(j,i-j)))
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};