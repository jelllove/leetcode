
class Solution {
private:
    int row[9] = {0};//记录每一行上的已经有的数字
    int col[9] = {0};//记录每一列上的已经有的数字
    int block[9] = {0};//记录每一块上的已经有的数字
    bool m_done = false; //如果已经找到了方案，就不用再做了
public:
    
    
    
    void dfs(vector<vector<char>>& board, int i)
    {
        if (m_done)
            return;
        //判断如果当前的格子已经填了，就只要判断一下，是不是已经到结尾了
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
            //如果还没有填过，就从1到9，一个个填过去试试
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
                
                //填了之后要把位MARK上
                row[i / 9] |= (1 << (board[i / 9][i % 9] - '0'));
                col[i % 9] |= (1 << (board[i / 9][i % 9] - '0'));
                block[((i/9) / 3)*3 + (i % 9) / 3] |= (1 << (board[i / 9][i % 9] - '0'));
                
                
                int x = i;
                
                
                //走到一个个格子
                dfs(board, ++x);
                
                if (m_done)
                {
                    return;
                }
                
                //如果填了之后发现不行，那就把刚才填的取消
                row[i / 9] &= ~(1 << (board[i / 9][i % 9] - '0'));
                col[i % 9] &= ~(1 << (board[i / 9][i % 9] - '0'));
                block[((i/9) / 3)*3 + (i % 9) / 3] &= ~(1 << (board[i / 9][i % 9] - '0'));
                
                //然后再把数字设置成空
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