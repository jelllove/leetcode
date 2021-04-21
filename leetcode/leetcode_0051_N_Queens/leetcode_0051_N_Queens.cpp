class Solution {
public:
    
    bool noConflict(vector<string> &b, int row, int col)
    {
        int i = 0;
        int j = 0;
        //判断是否有同一列上有相同的
        for (i = 0; i < row; ++i)
        {
            if (b[i][col] == 'Q')
                return false;
        }
        
        //判断左上角斜线有没有Q
        i = row - 1;
        j = col - 1;
        while (i >= 0 && j >= 0)
        {
            if (b[i][j] == 'Q')
                return false;
            --i;
            --j;
        }
        
        //判断右上角斜线有没有Q
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < b.size())
        {
            if (b[i][j] == 'Q')
                return false;
            --i;
            ++j;
        }
        
        return true;
    }
    
    void helper(vector<vector<string>> &ans, vector<string> &b, int count, int n)
    {
        //这里的count是指已经有多少个Q了
        //如果当前的count的数目与N相等了，那就可以直接返回了
        if (count == n)
        {
            ans.push_back(b);
            return;
        }
        
        //这里加Q的话，是从一行一行的加上去的，其实这里的count也相当于row index
        //然后新的这一行上，一个列一个列的去试，
        for (int j = 0; j < n; ++j)
        {
            if (noConflict(b, count, j))
            {
                //如果这个列上没有冲突的话，可以把Q放上去，然后再去一行试一下
                b[count][j] = 'Q';
                helper(ans, b, count + 1, n);
                //等下一行试完了，就把Q还原，因为这在回溯的过程中，这一行的这一列可能还有下一列
                b[count][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        //如果N=0,直接返回一个空
        if (n == 0)
            return vector<vector<string>>();
        
        //如果N=1，那就只能有一个Q
        if (n == 1)
            return vector<vector<string>>(1, vector<string>(1, "Q"));
        
        //先定义一个N*N的所有都是点的字符串数组
        vector<string> b(n, string(n, '.'));
        vector<vector<string>> ans;
        helper(ans, b, 0, n);
        
        return ans;
    }
};