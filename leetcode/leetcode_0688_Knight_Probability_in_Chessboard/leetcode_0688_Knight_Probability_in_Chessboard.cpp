class Solution {
public:
      double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n,0));
        
        
        vector<int> dr = {1, 1, 2, 2, -1, -1, -2, -2};
        vector<int> dc = {2, -2, 1, -1, 2, -2, 1, -1};
        
        dp[row][column] = 1;
        
        while(k > 0)
        {
            vector<vector<double>> dp2(n, vector<double>(n,0));
            
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<n; j++)
                {
                    for(int K = 0; K < 8; K++)
                    {
                        int r = i + dr[K];
                        int c = j + dc[K];
                        
                        if(r >= 0 && r < n && c >= 0 && c < n)
                        {
                            dp2[r][c] += dp[i][j]/8;
                        }
                    }
                }
            }
            
            dp = dp2;
            
            k--;
        }
        
        double prob = 0;
        
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                prob += dp[i][j];
            }
        }
        
        return prob;

    }
};