class Solution {
public:
    bool isMatch(string s, string p) {
        
        int m=p.size();
        int n=s.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j]=1;
                }
                else if(j==0)
                {
                    if(p[i-1]=='*')
                    {
                        dp[i][j]=dp[i-2][j];
                    }
                    else
                    {
                        dp[i][j]=0;
                    }
                }
                else if(i==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                   if(p[i-1]=='*')
                   {
                      if(p[i-2]==s[j-1]||p[i-2]=='.')
                      {
                        dp[i][j]=dp[i-2][j]||dp[i][j-1];
                      }
                      else
                      {
                          dp[i][j]=dp[i-2][j];
                      }
                   }
                   else if(p[i-1]=='.'||p[i-1]==s[j-1])
                   {
                       dp[i][j]=dp[i-1][j-1];
                   }
                   else
                   {
                       dp[i][j]=0;
                   }
                    
                }
                
            }
        }
        return dp[m][n];
    }
};