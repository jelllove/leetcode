class Solution {
public:
    
    void helper(vector<vector<int>> &grid, int i, int j, int rows, int cols, int sum, int &ret)
    {
        if (i >= rows || j >= cols)
            return;
        if ((i == rows - 1) && (j == cols - 1))
        {
            ret = min(ret, sum + grid[i][j]);
            return;
        }
        
        sum += grid[i][j];
        helper(grid, i + 1, j, rows, cols, sum, ret);
        helper(grid, i, j + 1, rows, cols, sum, ret);
            
    }
    
    int minPathSum(vector<vector<int>> grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        //get the row and cols amount
        int rows = grid.size();
        int cols = grid[0].size();
        
        //Method 1: DFS to go through all the possible, but finally it will out of time.
        /*
        int ret = std::numeric_limits<int>::max();
        helper(grid, 0, 0, rows, cols, 0, ret);
        return ret;
        */
        
        
        //Method 2: DP, using the m*n matrix as the DP array.
        
        //generate the dp array
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        //Assign the first element(cell)
        dp[0][0] = grid[0][0];
    
        //initial the first row and first col
        int i, j;
        for (i = 1; i < rows; ++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];

        for (j = 1; j < cols; ++j)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        
        //go through all the reset elements.
        for (int i = 1; i < rows; ++i)
        {
            for (int j = 1; j < cols; ++j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        
        return dp[rows - 1][cols - 1];
        
        
        
    }
};