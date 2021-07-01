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
        bool done = false;
        dfs(s1, 0, s2, 0, s3, 0, done);
        return done;
    }
};