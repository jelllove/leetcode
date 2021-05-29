class Solution {
public:
    
    
    void dfs(vector<vector<int>>& grid, int i, int j, bool &isLand)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 0)
            return;
        
        
        if (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1)
            isLand = false;
        
        grid[i][j] = 1;
        
        dfs(grid, i + 1, j, isLand);
        dfs(grid, i - 1, j, isLand);
        dfs(grid, i, j + 1, isLand);
        dfs(grid, i, j - 1, isLand);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j <  grid[0].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    bool isLand = true;
                    dfs(grid, i, j, isLand);
                    if (isLand)
                    {
                        ++ans;
                    }
                }
            }
        }
        
        return ans;
    }
};