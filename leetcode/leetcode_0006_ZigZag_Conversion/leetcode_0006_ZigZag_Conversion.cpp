class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <= 1 || numRows >= s.size())
            return s;
        
        vector<string> rows(numRows, "");
        
        int i = 0;
        int rowIdx = 0;
        int maxRows = numRows + (numRows - 2);
        while (i < s.size())
        {
            if (rowIdx < numRows)
            {
                rows[rowIdx] += s[i];
            }
            else
            {
                rows[maxRows - rowIdx] += s[i];
            }
            
            ++i;
            ++rowIdx;
            if (rowIdx >= maxRows)
                rowIdx = 0;
        }
        
        string ans = "";
        for (auto &r : rows)
            ans += r;
        
        return ans;
        
    }
};