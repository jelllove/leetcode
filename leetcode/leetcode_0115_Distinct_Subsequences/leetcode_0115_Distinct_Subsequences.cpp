class Solution {
public:
    
    //Method 1
    void dfs(string &s, int i, string &t, int j, int &count)
    {
        if (j >= t.size())
        {
            ++count;
            return;
        }
        
        if (i >= s.size())
            return;
        
        for (int m = i; m < s.size(); ++m)
        {
            if (s[m] == t[j])
            {
                dfs(s, m + 1, t, j + 1, count);
            }
        }
    }
    
    
    int numDistinct(string s, string t) {
        //Method 1: using the dfs + recursion, it is work, but too slow
        /*
        int count = 0;
        dfs(s, 0, t, 0, count);
        return count;
        */
        
        //Method 2: using the DP
        if (s.size() == 0 || t.size() == 0)
            return 0;
        
        vector<vector<unsigned long> > dp(t.size() + 1, vector<unsigned long>(s.size() + 1, 0));
        int i = 0, j = 0;
        
        dp[0][0] = 1;
        for (i = 1; i < t.size() + 1; ++i)
            dp[i][0] = 0;
        
        for (j = 1; j < s.size() + 1; ++j)
            dp[0][j] = 1;
        
        
        
        for (int i = 1; i < t.size() + 1; ++i)
        {
            for (int j = 1; j < s.size() + 1; ++j)
            {
                dp[i][j] = dp[i][j - 1];
                if (t[i - 1] == s[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        
        
        return dp[t.size()][s.size()];
        
        
    }
};