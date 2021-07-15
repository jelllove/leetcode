class Solution {
public:
    int minPathSum(vector<vector<int>> grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        //get the row and cols amount
        int rows = grid.size();
        int cols = grid[0].size();

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