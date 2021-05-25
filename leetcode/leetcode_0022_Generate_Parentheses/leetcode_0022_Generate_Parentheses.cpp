class Solution {
public:
    
    
    void helper(vector<string> &ans, string str, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            ans.push_back(str);
            return;
        }
            
        
        
        if (open > 0)
            helper(ans, str + "(", open - 1, close);
        
        if (close > open)
            helper(ans, str + ")", open, close - 1);
    }
    
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        
        helper(ans, str, n, n);
        
        return ans;
        
    }
};