class Solution {
public:
    bool ValidIndex(int row, int col, int i, int j)
    {
        if (i < 0 || j < 0 || i >= row || j >= col)
            return false;
        else
            return true;
    }
    
    vector<vector<int>> generateMatrix(int n) {
        
        if (n <= 0)
        {
            vector<vector<int>> vec(0, vector<int>(0));
            return vec;
        }
        
        //Method 1: using the direction flag to control the move direction.
        /*
        vector<vector<int>> matrix(n, vector<int>(n, 0));
            
        int rowCount = n;
        int colCount = n;
        
        int totalGirdCount = n * n;
        
        vector<vector<bool>> visitedList(rowCount, vector<bool>(colCount, false));
        
        // 0,1  =  Right move
        // 1,0  =  Down move
        // 
        vector<vector<int>> directionList = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int curDirectionIndex = 0;
        int i = 0, j = -1;
        int newI, newJ;
        int value = 1;
        while (value <= n*n)
        {
            newI = i + directionList[curDirectionIndex][0];
            newJ = j + directionList[curDirectionIndex][1];
            if (ValidIndex(rowCount, colCount, newI, newJ))
            {
                if (visitedList[newI][newJ])
                {
                    curDirectionIndex++;
                    if (curDirectionIndex >= directionList.size())
                    {
                        curDirectionIndex = 0;
                    }
                }
                else
                {
                    visitedList[newI][newJ] = true;
                    matrix[newI][newJ] = value++;
                    i = newI;
                    j = newJ;
                }
            }
            else
            {
                curDirectionIndex++;
                if (curDirectionIndex >= directionList.size())
                {
                    curDirectionIndex = 0;
                }
            }
        }
        
        return matrix;
        */
        
        //Method 2: using the variable
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        int idx = 1;
        int i = 0;
        while (top <= bottom || left <= right)
        {
            //这两个主要是处理只有一条横线或是竖线的时候
            if (top == bottom)
            {
                while (left <= right)
                {
                    ans[top][left++] = idx++;
                }
                break;
            }
            
            //这两个主要是处理只有一条横线或是竖线的时候
            if (left == right)
            {
                while (top <= bottom)
                {
                    ans[top++][left] = idx++;
                }
                break;
            }
            
            for (i = left; i < right; ++i)
                ans[top][i] = idx++;
            
            for (i = top; i < bottom; ++i)
                ans[i][right] = idx++;
            
            for (i = right; i > left; --i)
                ans[bottom][i] = idx++;
            
            for (i = bottom; i > top; --i)
                ans[i][left] = idx++;
            
            ++top;
            --right;
            --bottom;
            ++left;
        }
        
        return ans;
    }
};