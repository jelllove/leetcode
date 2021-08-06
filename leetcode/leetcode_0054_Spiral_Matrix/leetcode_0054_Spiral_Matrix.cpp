class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        //Method A:Using the flag to marked the accessed items
        //Easy to understand, but not quick
        /*
        vector<int> ans;
        
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        
        //使用一个数组来表示所有的点是否都访问过
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        
        //使用四个数组来表示X,Y轴的移动方向
        int direct[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int rows = matrix[0].size();
        int cols = matrix.size();
        int amount = rows * cols;//计算出总的item的个数
        int x = 0;
        int y = -1;
        int d = 0;
        
        //能让它停下的就是所有的元素都遍历过了
        while (ans.size() < amount)
        {
            //不能直接修改x,y的值，要利用一个中间变量
            int newX = x + direct[d][0];
            int newY = y + direct[d][1];
            
            if (newX >= 0 && newX < cols &&
                newY >= 0 && newY < rows)
            {
                //如果已经遇上一个访问过的，那就转向
                if (visited[newX][newY])
                {
                    ++d;
                    if (d >= 4)
                    {
                        d = 0;
                    }
                }
                else
                {
                    //如果没有访问，那就让记录下来，然后同时mark一下visited
                    visited[newX][newY] = true;
                    ans.push_back(matrix[newX][newY]);
                    x = newX;
                    y = newY;
                }
            }
            else
            {
                ++d;
                if (d >= 4)
                {
                    d = 0;
                }
            }
            
            
            
        }
        return ans;
        */
            
        //Method B: using the boundary to control the item traverse
        //Better and quick solution
        
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        
        
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        vector<int> ans(matrix.size() * matrix[0].size(), 0);
        int idx = 0;
        int i;
        while (left <= right && top <= bottom)
        {
            if (left == right)
            {
                for (i = top; i <= bottom; ++i)
                    ans[idx++] = matrix[i][left];
                break;
            }
            
            if (top == bottom)
            {
                for (i = left; i<= right; ++i)
                    ans[idx++] = matrix[top][i];
                break;
            }
            
            for (i = left; i < right; ++i)
                ans[idx++] = matrix[top][i];
            
            for (i = top; i < bottom; ++i)
                ans[idx++] = matrix[i][right];
            
            for (i = right; i > left; --i)
                ans[idx++] = matrix[bottom][i];
            
            for (i = bottom; i > top; --i)
                ans[idx++] = matrix[i][left];
            
            ++left;
            --right;
            ++top;
            --bottom;
        }
        
        return ans;
    }
};