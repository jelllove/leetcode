class Solution {

private:
    int count = 0;
public:
    
    bool valid(vector<vector<char>> &grid, int row, int col)
    {
        for (int i = 0; i < row; ++i)
        {
            if (grid[i][col] == 'Q')
                return false;
        }
        
        for (int i = row - 1, j = col -1; i >= 0 && j >= 0; --i, --j)
        {
            if (grid[i][j] == 'Q')
                return false;
        }
        
         for (int i = row - 1, j = col + 1; i >= 0 && j < grid.size(); --i, ++j)
        {
            if (grid[i][j] == 'Q')
                return false;
        }
        
        
        return true;
    }
    
    void helper(vector<vector<char>> &grid, int row)
    {
        if (row >= grid.size())
        {
            ++count;
            return;
        }
        
        for (int j = 0; j < grid.size(); ++j)
        {
            if (valid(grid, row, j))
            {
                grid[row][j] = 'Q';
                helper(grid, row + 1);
                grid[row][j] = '.';
            }
        }
            
    }
    
    
    int totalNQueens(int n) {
        if (n <= 1)
            return n;
        
        count = 0;
        vector<vector<char>> grid(n, vector<char>(n, '.'));
        
        helper(grid, 0);
        
        return count;
    }
};