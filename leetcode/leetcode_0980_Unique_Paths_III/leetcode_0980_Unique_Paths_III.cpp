class Solution {
public:
    
    //使用DFS，遍历所有格子
    //i, j代表要检查的位置
    //visit代表是否访问过，使用reference的话，速度会快一点
    //visitCount代表访问过的空白的个数
    //blankCount代表一共有多少个空白的格子
    //count如果遇上了一次终点 ，就加1
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>> &visit, int visitCount, int blankCount, int &count)
    {
        
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visit[i][j] || grid[i][j] == -1)
            return;
        
        
        //如果遇上了终点，
        if (grid[i][j] == 2)
        {
            //要判断一下是否已经把所有的空白都走过一遍了
            if (visitCount == blankCount)
                ++count;
            return;
        }
        else if (grid[i][j] == 0)
        {
            //如果是空白的话，要让visitCount加上
            ++visitCount;
        }
        
        //访问过的话，都要标记上
        visit[i][j] = true;
        
        //四个方向都走一下
        dfs(grid, i + 1, j, visit, visitCount, blankCount, count);
        dfs(grid, i - 1, j, visit, visitCount, blankCount, count);
        dfs(grid, i, j + 1, visit, visitCount, blankCount, count);
        dfs(grid, i, j - 1, visit, visitCount, blankCount, count);
        
        //等上面的方向都走过的话，那再把它标记取消
        visit[i][j] = false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        
        bool found = false;
        int count = 0;
        int visitCount = 0;
        int blankCount = 0;
        int iPos = 0;
        int jPos = 0;
        for (int i = 0; i < grid.size() && !found; ++i)
        {
            for (int j = 0; j < grid[0].size() && !found; ++j)
            {
                if (grid[i][j] == 1)
                {
                    iPos = i;
                    jPos = j;
                }
                else if (grid[i][j] == 0)
                {
                    ++blankCount;
                }
                    
            }
        }
        
        
        
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
                    
        dfs(grid, iPos, jPos, visit, visitCount, blankCount, count);
                    
        return count;
    }
};