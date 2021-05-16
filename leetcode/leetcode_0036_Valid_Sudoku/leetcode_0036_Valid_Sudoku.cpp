class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //Method 1: using the hash
        /*
        unordered_map<int, bool> row_hash[9];
        unordered_map<int, bool> col_hash[9];
        
        
        unordered_map<int, bool> block_hash[9];
        
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int val = board[i][j] - '0';
                    if (row_hash[i].count(val) > 0 || col_hash[j].count(val) > 0)
                        return false;
                    
                    if (block_hash[(i/3) * 3 + (j / 3)].count(val) > 0)
                        return false;
                    
                    row_hash[i][val] = true;
                    col_hash[j][val] = true;
                    block_hash[(i/3) * 3 + (j / 3)][val] = true;
                }
            }
        }
        
        return true;
        */
        //Method 2: using the vector
        /*
        vector<vector<bool>> row_list(9, vector<bool>(9, false));
        vector<vector<bool>> col_list(9, vector<bool>(9, false));
        vector<vector<bool>> block_list(9, vector<bool>(9, false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int val = board[i][j] - '0' - 1;
                    if (row_list[i][val] || 
                        col_list[j][val] || 
                        block_list[(i/3) * 3 + (j / 3)][val])
                        return false;
                    
                    row_list[i][val] = true;
                    col_list[j][val] = true;
                    block_list[(i/3) * 3 + (j / 3)][val] = true;
                }
            }
        }
        
        return true;
        */
        
        //Method 3 using bits
        int sudoku[9] = {0};
        int row[9] = {0};
        int col[9] = {0};
        int val = 0;
        int block = 0;
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    val = board[i][j] - '0';
                    block = (i/3) * 3 + (j / 3);
                    if ((sudoku[block] & (1 << val)) ||
                        (row[i] & (1 << val)) ||
                        (col[j] & (1 << val))
                        )
                    {
                        return false;
                    }
                    else
                    {
                        sudoku[block] |= (1 << val);
                        row[i] |= (1 << val);
                        col[j] |= (1 << val);
                    }
                }
            }
        }
        
        return true;
        
        
    }
};