
class Solution {
private:
    int row[9] = {0};//记录每一行上的
    int col[9] = {0};
    int block[9] = {0};
    bool m_done = false;
public:
    
    
    
    void dfs(vector<vector<char>>& board, int i)
    {
        if (m_done)
            return;
        
        if (board[i / 9][i % 9] != '.')
        {
            if (i == 80)
            {
                m_done = true;
                return;
            }
            
            dfs(board, ++i);
        }
        else
        {
            for (int m = 1; m <= 9 && !m_done; ++m)
            {
                if (row[i / 9] & (1 << m))
                    continue;
                
                if (col[i % 9] & (1 << m))
                    continue;
                
                if (block[((i/9) / 3)*3 + (i % 9) / 3] & (1 << m))
                    continue;
                
                board[i / 9][i % 9] = m + '0';
                
                if (i == 80)
                {
                    m_done = true;
                    return;
                }
                
                
                row[i / 9] |= (1 << (board[i / 9][i % 9] - '0'));
                col[i % 9] |= (1 << (board[i / 9][i % 9] - '0'));
                block[((i/9) / 3)*3 + (i % 9) / 3] |= (1 << (board[i / 9][i % 9] - '0'));
                
                
                int x = i;
                
                
                
                dfs(board, ++x);
                
                if (m_done)
                {
                    return;
                }
                
                
                row[i / 9] &= ~(1 << (board[i / 9][i % 9] - '0'));
                col[i % 9] &= ~(1 << (board[i / 9][i % 9] - '0'));
                block[((i/9) / 3)*3 + (i % 9) / 3] &= ~(1 << (board[i / 9][i % 9] - '0'));
                
                
                board[i / 9][i % 9] = '.';
                
            }
        }
        
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {    
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    row[i] |= (1 << (board[i][j] - '0'));
                    col[j] |= (1 << (board[i][j] - '0'));
                    block[(i / 3) * 3 + j / 3] |= (1 << (board[i][j] - '0'));
                }
            }
        }
        
        dfs(board, 0);
    }
};