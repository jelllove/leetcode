class Solution {
public:
    
    
    void helper(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        
        helper(grid, i + 1, j);
        helper(grid, i - 1, j);
        helper(grid, i, j + 1);
        helper(grid, i, j - 1);
    }
    
    
    void helper2(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &visited)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j])
            return;
        
        visited[i][j] = true;
        
        helper2(grid, i + 1, j, visited);
        helper2(grid, i - 1, j, visited);
        helper2(grid, i, j + 1, visited);
        helper2(grid, i, j - 1, visited);
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.size() == 0)
            return 0;
        
        int ans = 0;
        
        
        //Method 1: 遍历，同时不修改值
        //遍历所有的元素，然后如果发现了一个1的话，就计一下数
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    helper2(grid, i, j, visited);
                    
                    ++ans;
                }
            }
        }
        
        //Method 2: 遍历，同时修改元素
        //遍历所有的元素，然后如果发现了一个1的话，就计一下数
        //如果同时使用DFS进行一个递归，把这个1，以及它周边相连的所有的1，都填成0
        //这样下次就不会遇上了
        /*
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    helper(grid, i, j);
                    
                    ++ans;
                }
            }
        }
        */
        
        return ans;
        
    }
};