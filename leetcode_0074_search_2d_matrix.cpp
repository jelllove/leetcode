#include "public.h"



class Solution {
public:
    
    int getValueByIndex(vector<vector<int>>& matrix, int index)
    {
        size_t rows = matrix.size();
        size_t cols = (rows > 0 ? matrix[0].size() : 0);
        
        long long total = rows * cols;
        
        if (index < 0 || index >= total)
        {
            return INT_MIN;
        }
        else
        {
            int rowIndex = index / cols;
            int colIndex = index % cols;
            
            return matrix[rowIndex][colIndex];
        }
            
    }
    
    bool binaryFind(vector<vector<int>>& matrix, int leftIndex, int rightIndex, int &target)
    {
        if (leftIndex >= rightIndex)
        {
            if (getValueByIndex(matrix, leftIndex) == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int midIndex = ((rightIndex - leftIndex) / 2) + leftIndex;
            int value = getValueByIndex(matrix, midIndex);
            if (value == target)
            {
                return true;
            }
            else if (value > target)
            {
                return binaryFind(matrix, leftIndex, midIndex - 1, target);
            }
            else
            {
                return binaryFind(matrix, midIndex + 1, rightIndex, target);
            }
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
        size_t rows = matrix.size();
        size_t cols = (rows > 0 ? matrix[0].size() : 0);
        
        long long total = rows * cols;
        
        return binaryFind(matrix, 0, total - 1, target);
    }
};

int main()
{

    vector<vector<int>> vecInput = {{1}, {3}};
    cout << Solution().searchMatrix(vecInput, 2);
    return 0;
}