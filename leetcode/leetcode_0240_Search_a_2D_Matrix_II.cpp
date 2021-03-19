#include "../include/public.h"

/*
//Solution A: binary find per each line
//Low efficiency
class Solution {
public:
    
    bool binaryFind(vector<vector<int>>& matrix, int row, int target)
    {
        int l = 0, r = matrix[row].size() - 1;
        
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return (matrix[row][l] == target);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i].front() <= target && target <= matrix[i].back())
            {
                if (binaryFind(matrix, i, target))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
*/

//Solution B: 
//High efficiency
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size()-1; 
        int n= matrix[0].size()-1;
        int i = 0;
        int j = n;
        while ( i<= m && j >=0)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j;
            else
                ++i;
        }
        return false;
    }
};