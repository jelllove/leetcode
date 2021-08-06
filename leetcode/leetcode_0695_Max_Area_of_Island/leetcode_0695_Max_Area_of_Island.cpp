class Solution {
public:
    
    int helper(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0)
            return 0;
        
        visited[i][j] = true;
        
        return helper(grid, i + 1, j, visited) + 
               helper(grid, i, j + 1, visited) +
               helper(grid, i - 1, j, visited) + 
               helper(grid, i, j - 1, visited) + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        int maxArea = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    maxArea = max(helper(grid, i, j, visited), maxArea);
                }
            }
        }
        
        return maxArea;
    }
};