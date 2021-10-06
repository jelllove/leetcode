class Solution {
    // check O should equal to X or one less than X
    // no more than one player is winning the game horizontally
    // no more than one player is winning the game vertically

    // one who is winnign the game would be the last to finish
public:
    bool validTicTacToe(vector<string>& board) {
        int hwins = 0, vwins = 0;
        bool xwins = false, owins = false;

        for (int i = 0; i < 3; ++i)
        {
            if (board[i][0] == ' ') continue;
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                hwins++;
                if (board[i][0] == 'X') xwins = true;
                else owins = true;
            }
            if (i == 0) {
                if (board[i][0] == board[i + 1][1] && board[i + 1][1] == board[i + 2][2])
                    if (board[i][0] == 'X') xwins = true;
                    else owins = true;
            }
            if (i == 2) {
                if (board[i][0] == board[i - 1][1] && board[i - 1][1] == board[i - 2][2])
                    if (board[i][0] == 'X') xwins = true;
                    else owins = true;
            }
        }

        for (int i = 0; i < 3; ++i)
        {
            if (board[0][i] == ' ') continue;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                vwins++;
                if (board[0][i] == 'X') xwins = true;
                else owins = true;
            }
        }
        if (hwins > 1 || vwins > 1) return false;

        int x = 0, o = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == 'X') x++;
                else if (board[i][j] == 'O') o++;

        if (owins) return o == x;
        if (xwins) return o == x - 1;
        return (o == x || o == x - 1);
    }
};