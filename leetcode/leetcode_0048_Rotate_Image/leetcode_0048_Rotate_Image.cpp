class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        
        for (auto &item : matrix)
        {
            reverse(item.begin(), item.end());
        }
    
    }
};