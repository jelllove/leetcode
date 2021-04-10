class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        //Method 1: 利用第一行，和第一列记录这一行上是否有0
        bool firstRowZero = false;
        bool firstColZero = false;
        
        int i, j;
        
        for (i = 0; i < matrix.size(); ++i)
        {
            for (j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    
                    if (i == 0)
                        firstRowZero = true;
                    
                    if (j == 0)
                        firstColZero = true;
                }
            }
        }
        
        
        for (i = 1; i < matrix.size(); ++i)
        {
            if (matrix[i][0] == 0)
            {
                for (j = 0; j < matrix[0].size(); ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        for (j = 1; j < matrix[0].size(); ++j)
        {
            if (matrix[0][j] == 0)
            {
                for (i = 0; i < matrix.size(); ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (firstRowZero)
        {
            for (j = 0; j < matrix[0].size(); ++j)
            {
                matrix[0][j] = 0;
            }
        }
        
        
        if (firstColZero)
        {
            for (i = 0; i < matrix.size(); ++i)
            {
                matrix[i][0] = 0;
            }
        }
        
        
        
        
        //Method 2: 记录所有的0，然后根据行与列，一个个填0
        /*
        unordered_set<int> row;
        unordered_set<int> col;
        
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        
        for (auto &rowIndex: row)
        {
            for (int m = 0; m < matrix[0].size(); ++m)
            {
                matrix[rowIndex][m] = 0;
            }
        }
        
        for (auto &colIndex: col)
        {
            for (int m = 0; m < matrix.size(); ++m)
            {
                matrix[m][colIndex] = 0;
            }
        }
        */
        
    }
};