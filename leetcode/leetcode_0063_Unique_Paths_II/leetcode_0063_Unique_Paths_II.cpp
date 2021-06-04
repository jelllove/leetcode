class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        //Method 1: DP
        //先判断有没有数据，如果有的话，第一个起点不能是石头
        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1)
            return 0;
        
        //生成一个动态数组，默认所有的可能性都先设置为0
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        
        //因为在前面判断过了，第一个不是石头，所以第一个格子的可能性是1
        dp[0][0] = 1;
        
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        //逐行逐列的进行扫描
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                //遇上不是石头的，才能进行DP的更新
                if (obstacleGrid[i][j] == 0)
                {
                    //前一个肯定要有数据
                    if (i > 0)
                        dp[i][j] += dp[i - 1][j];
                    
                    if (j > 0)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
};