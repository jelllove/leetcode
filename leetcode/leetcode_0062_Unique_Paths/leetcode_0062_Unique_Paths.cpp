class Solution {
public:
    
    void helper(int i, int j, int m, int n, int &ans)
    {
        if (i >= m || j >= n)
            return;
        
        if (i == (m -1) || j == (n - 1))
        {
            ++ans;
            return;
        }
        
        helper(i + 1, j, m, n, ans);
        helper(i, j + 1, m, n, ans);
        
    }
    
    int uniquePaths(int m, int n) {
        
        //Method 1: using the recursion, the method is right, but timeout
        /*
        if (m <= 0 || n <= 0)
            return 0;
        
        int ans = 0;
        helper(0, 0, m, n, ans);
        
        return ans;
        */
        
        //Method 2: dp
    
        if (m <= 0 || n <= 0)
            return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
        
    }
};