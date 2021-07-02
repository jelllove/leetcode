class Solution {
public:
    
    void dfs(string &s1, int i, string &s2, int j, string &s3, int k, bool &done)
    {
        if (done)
            return;
        
        if (k == s3.size())
        {
            done = true;
            return;
        }
        
        
        if (s1[i] != s3[k] && s2[j] != s3[k])
        {
            return;
        }
        
        if (i < s1.size() && s1[i] == s3[k])
            dfs(s1, i + 1, s2, j, s3, k + 1, done);
        
        
        if (!done && j < s2.size() && s2[j] == s3[k])
            dfs(s1, i, s2, j + 1, s3, k + 1, done);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if ((s1.size() + s2.size()) != s3.size())
            return false;
        
        //Method 1: using the dfs+ backtrace, but time out
        /*
        bool done = false;
        dfs(s1, 0, s2, 0, s3, 0, done);
        return done;
        */
        
        //Method 2: using the DP
        //生成一个两维数组，行数等于S1的个数，列数等于S2的个数，然后再加一行加一列
        vector<vector<bool> > dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        
        dp[0][0] = true;//第一个点是没有相交的点，所以默认是可以的
        
        //把第一列上的每个元素比较一下，如果有相同的话，就标记成true 
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == s3[i])
                dp[i + 1][0] = true;
            else
                break;
        }
        
        //把第一行上的每个元素比较一下，如果有相同的话，就标记成true 
        for (int j = 0; j < s2.size(); ++j)
        {
            if (s2[j] == s3[j])
                dp[0][j + 1] = true;
            else
                break;
        }
        
        //使用i + j的位置与s1和s2进行比较，在比较行的时候，要求它的上一行，同一个列也要是TRUE，
        //在比较列的时候，要求它同一行的前一列的元素，也是TRUE
        for (int i = 0; i < s1.size(); ++i)
        {
            for (int j = 0; j < s2.size(); ++j)
            {
                if (s1[i] == s3[i + j + 1] && dp[i][j + 1])
                    dp[i + 1][j + 1] = true;
                else if (s2[j] == s3[i + j + 1] && dp[i + 1][j])
                    dp[i + 1][j + 1] = true;
            }
        }
        
        //返回最后一个元素
        return dp[s1.size()][s2.size()];
        
            
    }
};