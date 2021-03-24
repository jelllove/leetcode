


class Solution {
public:
    size_t rows = 0;
    size_t cols = 0;
    
    bool binaryFind(vector<vector<int>>& matrix, int l, int r, int &target)
    {
        while (l < r)
        {
            int m = (r - l) / 2 + l; //得到中间值，先减后加，这样可以防止溢出
            
            if (matrix[m / cols][m % cols] == target)
                return true;
            else if (matrix[m / cols][m % cols] > target)   //根据index在二维表中找到对应的行与列
                r = m - 1;
            else
                l = m + 1;
        }
        
        if (matrix[l / cols][l % cols] == target)//最后两个l 和 r重合了
            return true;
        else
            return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        rows = matrix.size();
        cols = (rows > 0 ? matrix[0].size() : 0);
        
        
        return binaryFind(matrix, 0, (rows * cols) - 1, target);
    }
};